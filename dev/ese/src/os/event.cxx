// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "osstd.hxx"


ULONG g_cbEventHeapMax;

#include <malloc.h>


LOCAL CRITICAL_SECTION g_csEventCache;
LOCAL BOOL g_fcsEventCacheInit;

#ifdef DISABLE_EVENT_LOG

void COSLayerPreInit::SetEventLogCache( ULONG cbEventCache ) {}

#else


NTOSFuncPD( g_pfnRegisterEventSourceW, RegisterEventSourceW );
NTOSFuncPD( g_pfnReportEvent, ReportEventW );
NTOSFuncPD( g_pfnDeregisterEventSource, DeregisterEventSource );


LOCAL volatile HANDLE g_hEventSource;

#pragma warning ( disable : 4200 )

struct EVENT
{
    SIZE_T          cb;
    EVENT*          peventNext;
    const WCHAR*    szSourceEventKey;
    EEventType      type;
    CategoryId      catid;
    MessageId       msgid;
    DWORD           cbRawData;
    void*           pvRawData;
    DWORD           cString;
    const WCHAR*    rgpsz[0];
};

LOCAL EVENT*        g_peventCacheHead;
LOCAL EVENT*        g_peventCacheTail;
LOCAL DWORD         g_ceventLost;
LOCAL SIZE_T        cbEventCache;

void COSLayerPreInit::SetEventLogCache( ULONG cbEventCacheSet )
{
    g_cbEventHeapMax = cbEventCacheSet;
}


void OSEventIFlushEventCache()
{
    EVENT*  peventPrev  = NULL;
    EVENT*  pevent;
    EVENT*  peventNext;


    for ( pevent = g_peventCacheHead; NULL != pevent; pevent = peventNext )
    {
        peventNext = pevent->peventNext;

        g_hEventSource = g_pfnRegisterEventSourceW( NULL, pevent->szSourceEventKey );
        if ( g_hEventSource )
        {
            SIZE_T  cbAlloc     = pevent->cb;

            if ( NULL == peventPrev )
            {
                Assert( pevent == g_peventCacheHead );
                g_peventCacheHead = pevent->peventNext;
            }
            else
            {
                peventPrev->peventNext = pevent->peventNext;
            }
            if ( pevent == g_peventCacheTail )
                g_peventCacheTail = peventPrev;

            (void)g_pfnReportEvent( g_hEventSource,
                                    WORD( pevent->type ),
                                    WORD( pevent->catid ),
                                    pevent->msgid,
                                    0,
                                    WORD( pevent->cString ),
                                    WORD( pevent->cbRawData ),
                                    (const WCHAR**)pevent->rgpsz,
                                    pevent->pvRawData );

            const BOOL  fFreedEventMemory   = !LocalFree( pevent );
            Assert( fFreedEventMemory );

            g_pfnDeregisterEventSource( g_hEventSource );
            g_hEventSource = NULL;

            Assert( cbEventCache >= cbAlloc );
            cbEventCache -= cbAlloc;
        }
        else
        {
            peventPrev = pevent;
        }
    }

    Assert( NULL == g_peventCacheHead ? NULL == g_peventCacheTail : NULL != g_peventCacheTail );


    if ( g_ceventLost )
    {
        g_ceventLost = 0;
    }
}

#endif

#ifdef DEBUG
LOCAL BOOL  g_fOSSuppressEvents   = fFalse;
#endif


const size_t    g_cLastEvent                        = 10;
WCHAR*          g_rgwszLastEvent[ g_cLastEvent ]    = { NULL };
size_t          g_iLastEvent                        = 0;


void OSEventReportEvent(    const WCHAR*        szSourceEventKey,
                            const EEventFacility eventfacility,
                            const EEventType    type,
                            const CategoryId    catid,
                            const MessageId     msgid,
                            const DWORD         cString,
                            const WCHAR*        rgpszString[],
                            const DWORD         cbRawData,
                            void*               pvRawData )
{
    Expected( eventfacility & eventfacilityOsDiagTracking );
    Expected( eventfacility & eventfacilityRingBufferCache );
    Expected( eventfacility & eventfacilityOsEventTrace );
    Expected( eventfacility & eventfacilityOsTrace );

    OnThreadWaitBegin();
    EnterCriticalSection( &g_csEventCache );
    OnThreadWaitEnd();

#ifdef DEBUG
    if ( g_fOSSuppressEvents )
    {
        LeaveCriticalSection( &g_csEventCache );
        return;
    }
    g_fOSSuppressEvents = fTrue;
#endif

    LPWSTR wszEvent = NULL;
    if ( FormatMessageW( (  FORMAT_MESSAGE_ALLOCATE_BUFFER |
                            FORMAT_MESSAGE_ARGUMENT_ARRAY |
                            FORMAT_MESSAGE_FROM_HMODULE |
                            FORMAT_MESSAGE_MAX_WIDTH_MASK ),
                        PvUtilImageBaseAddress(),
                        msgid,
                        MAKELANGID( LANG_NEUTRAL, SUBLANG_NEUTRAL ),
                        LPWSTR( &wszEvent ),
                        0,
                        (va_list *)rgpszString ) )
    {
        const WCHAR * wszLogStrFormatter = L"EventLog[ID=%d(0x%x)@%I64d]:  %ws";
        const INT cchLogStr = wcslen( wszLogStrFormatter ) + 10  + 8  + 20  + wcslen( wszEvent ) + 1 ;
        WCHAR * wszLogStr = (WCHAR*)LocalAlloc( LMEM_FIXED, cchLogStr * sizeof(WCHAR) );
        if ( wszLogStr )
        {
            OSStrCbFormatW( wszLogStr, cchLogStr*sizeof(WCHAR), wszLogStrFormatter, msgid, msgid, HrtHRTCount(), wszEvent );
            LocalFree( wszEvent );
            wszEvent = NULL;
        }
        else
        {
            wszLogStr = wszEvent;
            wszEvent = NULL;
        }

        if ( eventfacility & eventfacilityOsTrace )
        {
            OSTrace( JET_tracetagEventlog, OSFormat( "%hs", SzOSFormatStringW( wszLogStr ) ) );
        }

        if ( eventfacility & eventfacilityOsEventTrace )
        {
            switch ( type )
            {
                case eventError:
                    ETEventLogError( wszLogStr );
                    break;
                case eventWarning:
                    ETEventLogWarn( wszLogStr );
                    break;
                default:
                    AssertSz( fFalse, "If we have anything else, someone should figure this out (as maybe someone added Critical event support, which shouldn't masquerade as Info): %d", type );
                case eventInformation:
                    ETEventLogInfo( wszLogStr );
                    break;
            }
        }

        if ( eventfacility & eventfacilityRingBufferCache )
        {
            if ( g_rgwszLastEvent[ g_iLastEvent ] )
            {
                LocalFree( g_rgwszLastEvent[ g_iLastEvent ] );
                g_rgwszLastEvent[ g_iLastEvent ] = NULL;
            }
            g_rgwszLastEvent[ g_iLastEvent ] = wszLogStr;
            wszLogStr = NULL;
            g_iLastEvent = ( g_iLastEvent + 1 ) % g_cLastEvent;
        }
        else
        {
            LocalFree( wszLogStr );
            wszLogStr = NULL;
        }

        Assert( wszEvent == NULL );
        Assert( wszLogStr == NULL );
    }


    if ( ( type == eventWarning ) || ( type == eventError ) )
    {
        if ( eventfacility & eventfacilityOsDiagTracking )
        {
            OSDiagTrackEventLog( msgid );
        }
    }
    else
    {
        AssertSz( ( type == eventSuccess ) || ( type == eventInformation ),
            "New event type %d, please determine whether or not it should be tracked in OS Diagnostics.",
            (INT)type );
    }

#ifndef DISABLE_EVENT_LOG

    NTOSFuncPtrPreinit( g_pfnRegisterEventSourceW, g_mwszzEventLogLegacyLibs, RegisterEventSourceW, oslfExpectedOnWin5x | oslfStrictFree | oslfNotExpectedOnCoreSystem );
    NTOSFuncStdPreinit( g_pfnReportEvent, g_mwszzEventLogLegacyLibs, ReportEventW, oslfExpectedOnWin5x | oslfStrictFree | oslfNotExpectedOnCoreSystem );
    NTOSFuncStdPreinit( g_pfnDeregisterEventSource, g_mwszzEventLogLegacyLibs, DeregisterEventSource, oslfExpectedOnWin5x | oslfStrictFree | oslfNotExpectedOnCoreSystem );


    Assert( !g_hEventSource );

    Assert( cbRawData == 0 || pvRawData != NULL );


    if ( eventfacility & eventfacilityReportOsEvent )
    {
        

        if ( NULL != g_peventCacheHead )
            OSEventIFlushEventCache();


        g_hEventSource = g_pfnRegisterEventSourceW( NULL, szSourceEventKey );

        
        if ( !g_hEventSource )
        {

            EVENT*          pevent              = NULL;
            SIZE_T          cbAlloc             = sizeof(EVENT);

            const DWORD     cbRawDataAlligned   = sizeof(WCHAR) * ( ( cbRawData + sizeof(WCHAR) - 1 ) / sizeof(WCHAR) );
            Assert( cbRawDataAlligned >= cbRawData );
            Assert( cbRawDataAlligned % sizeof(WCHAR) == 0 );
            
            cbAlloc += sizeof(WCHAR) * LOSStrLengthW( szSourceEventKey ) + sizeof(WCHAR );

            cbAlloc += sizeof(const WCHAR*) * cString;

            for ( DWORD ipsz = 0; ipsz < cString; ipsz++ )
            {
                cbAlloc += sizeof(WCHAR) * LOSStrLengthW( rgpszString[ipsz] ) + sizeof(WCHAR);
            }

            cbAlloc += cbRawDataAlligned;

            if ( cbEventCache + cbAlloc < (SIZE_T)g_cbEventHeapMax )
            {
                pevent = (EVENT*)LocalAlloc( LMEM_FIXED | LMEM_ZEROINIT, cbAlloc );
                if ( pevent )
                {
                    cbEventCache += cbAlloc;
                }
            }


            if ( !pevent )
            {

                g_ceventLost++;
            }


            else
            {
                WCHAR*      psz;

                pevent->cb = cbAlloc;
                pevent->peventNext = NULL;
                pevent->type = type;
                pevent->catid = catid;
                pevent->msgid = msgid;
                pevent->cbRawData = cbRawData;
                pevent->cString = cString;

                psz = (WCHAR*)( (BYTE*)pevent->rgpsz + ( sizeof(const WCHAR*) * cString ) );
        
                pevent->szSourceEventKey = psz;
                OSStrCbCopyW( psz, cbAlloc - (((BYTE*)psz)-(BYTE*)pevent), szSourceEventKey );
                psz += 1 + LOSStrLengthW( szSourceEventKey );

                if ( cbRawData > 0 )
                {
                    pevent->pvRawData = (void*)psz;
                    memcpy( psz, pvRawData, cbRawData );

                    Assert( cbRawDataAlligned % sizeof(WCHAR) == 0 );
                    psz += cbRawDataAlligned/sizeof(WCHAR);
                }
                else
                {
                    Assert( cbRawDataAlligned == 0 );
                    pevent->pvRawData = NULL;
                }

                for ( DWORD ipsz = 0; ipsz < cString; ipsz++ )
                {
                    pevent->rgpsz[ipsz] = psz;
                    OSStrCbCopyW( psz, cbAlloc - (((BYTE*)psz)-(BYTE*)pevent), rgpszString[ipsz] );
                    psz += 1 + LOSStrLengthW( rgpszString[ipsz] );
                }

                if ( ( (BYTE*)psz - (BYTE*)pevent ) == (LONG_PTR)cbAlloc )
                {
                    if ( NULL != g_peventCacheTail )
                    {
                        Assert( NULL != g_peventCacheHead );
                        g_peventCacheTail->peventNext = pevent;
                    }
                    else
                    {
                        Assert( NULL == g_peventCacheHead );
                        g_peventCacheHead = pevent;
                    }
                    g_peventCacheTail = pevent;
                }
                else
                {
                    Assert( fFalse );
                    const BOOL  fFreedEventMemory = !LocalFree( pevent );
                    Assert( fFreedEventMemory );
                }

            }
        }


        else
        {

            (void)g_pfnReportEvent( g_hEventSource,
                                    WORD( type ),
                                    WORD( catid ),
                                    msgid,
                                    0,
                                    WORD( cString ),
                                    WORD( cbRawData ),
                                    rgpszString,
                                    pvRawData );

            g_pfnDeregisterEventSource( g_hEventSource );
            g_hEventSource = NULL;
        }

    }

#endif

#ifdef DEBUG
    g_fOSSuppressEvents = fFalse;
#endif

    LeaveCriticalSection( &g_csEventCache );
}


void OSEventPostterm()
{
#ifndef DISABLE_EVENT_LOG
    Assert( !g_hEventSource || FUtilProcessAbort() );


    if ( NULL != g_peventCacheHead )
    {
        Assert( NULL != g_peventCacheTail );

        if ( g_hEventSource )
        {
            Assert( FUtilProcessAbort() );
            g_pfnDeregisterEventSource( g_hEventSource );
            g_hEventSource = NULL;
        }
        OSEventIFlushEventCache();

        EVENT*  pevent;
        EVENT*  peventNext;
        for ( pevent = g_peventCacheHead; pevent; pevent = pevent = peventNext )
        {
            peventNext = pevent->peventNext;
            const BOOL  fFreedEventMemory   = !LocalFree( pevent );
            Assert( fFreedEventMemory );
        }
    }
    else
    {
        Assert( NULL == g_peventCacheTail );
    }


    if ( g_hEventSource )
    {
        Assert( FUtilProcessAbort() );


        Assert( NULL == g_peventCacheHead );
        Assert( NULL == g_peventCacheTail );


        g_pfnDeregisterEventSource( g_hEventSource );
        g_hEventSource = NULL;
    }


    g_peventCacheHead = NULL;
    g_peventCacheTail = NULL;
    g_ceventLost      = 0;
    cbEventCache    = 0;
#endif


    for ( size_t iLastEvent = 0; iLastEvent < g_cLastEvent; iLastEvent++ )
    {
        if ( g_rgwszLastEvent[ iLastEvent ] )
        {
            LocalFree( g_rgwszLastEvent[ iLastEvent ] );
            g_rgwszLastEvent[ iLastEvent ] = NULL;
        }
    }
    g_iLastEvent = 0;


    if( g_fcsEventCacheInit )
    {
        DeleteCriticalSection( &g_csEventCache );
        g_fcsEventCacheInit = fFalse;
    }
}


BOOL FOSEventPreinit()
{
#ifndef DISABLE_EVENT_LOG

    g_cbEventHeapMax = 0;
#endif

    if ( !InitializeCriticalSectionAndSpinCount( &g_csEventCache, 0 ) )
    {
        goto HandleError;
    }
    g_fcsEventCacheInit = fTrue;


    for ( size_t iLastEvent = 0; iLastEvent < g_cLastEvent; iLastEvent++ )
    {
        g_rgwszLastEvent[ iLastEvent ] = NULL;
    }
    g_iLastEvent = 0;

#ifndef DISABLE_EVENT_LOG

    g_peventCacheHead = NULL;
    g_peventCacheTail = NULL;
    g_ceventLost      = 0;
    cbEventCache    = 0;


#endif

    return fTrue;

HandleError:
    OSEventPostterm();
    return fFalse;
}

VOID OSEventRegister()
{
#ifndef OFFICIAL_BUILD
#ifdef OS_LAYER_VIOLATIONS
    NTOSFuncError( pfnRegCreateKeyExW, g_mwszzRegistryLibs, RegCreateKeyExW, oslfExpectedOnWin5x | oslfRequired );
    NTOSFuncError( pfnRegQueryValueExW, g_mwszzRegistryLibs, RegQueryValueExW, oslfExpectedOnWin5x | oslfRequired );
    NTOSFuncError( pfnRegSetValueExW, g_mwszzRegistryLibs, RegSetValueExW, oslfExpectedOnWin5x | oslfRequired );
    NTOSFuncError( pfnRegCloseKey, g_mwszzRegistryLibs, RegCloseKey, oslfExpectedOnWin5x | oslfRequired );

    if ( 0 != _wcsicmp( WszUtilImageName(), L"ESElibwithtests" ) )
    {
        Expected( 0 == _wcsicmp( WszUtilImageName(), L"ESE" ) || 0 == _wcsicmp( WszUtilImageName(), L"ESENT" ) );

        static const WCHAR wszApplicationKeyPath[] = L"SYSTEM\\CurrentControlSet\\Services\\EventLog\\Application\\";
        WCHAR wszImageKeyPath[ sizeof( wszApplicationKeyPath ) / sizeof( wszApplicationKeyPath[0] ) + _MAX_FNAME ];
        OSStrCbFormatW( wszImageKeyPath, sizeof(wszImageKeyPath), L"%ws%.*ws", wszApplicationKeyPath, _MAX_FNAME, WszUtilImageVersionName() );

        DWORD error;
        HKEY hkeyImage;
        DWORD Disposition;
        error = pfnRegCreateKeyExW( HKEY_LOCAL_MACHINE,
                                    wszImageKeyPath,
                                    0,
                                    NULL,
                                    REG_OPTION_NON_VOLATILE,
                                    KEY_READ | KEY_WRITE,
                                    NULL,
                                    &hkeyImage,
                                    &Disposition );
        if ( error == ERROR_SUCCESS )
        {
            DWORD           dwType = 0;
            WCHAR           rgbData[ _MAX_PATH ];
            const size_t    cbDataMax   = sizeof( rgbData );
            DWORD           cbData;
            DWORD           Data;

            cbData = cbDataMax;
            if (    pfnRegQueryValueExW(    hkeyImage,
                                            L"EventMessageFile",
                                            0,
                                            &dwType,
                                            LPBYTE(rgbData),
                                            &cbData ) != ERROR_SUCCESS ||
                    dwType != REG_EXPAND_SZ ||
                    wcscmp( rgbData, WszUtilImagePath() ) ||
                    cbData != ( wcslen( WszUtilImagePath() ) + 1 ) * sizeof( WCHAR ) )
            {
                error = pfnRegSetValueExW(  hkeyImage,
                                            L"EventMessageFile",
                                            0,
                                            REG_EXPAND_SZ,
                                            LPBYTE( WszUtilImagePath() ),
                                            (ULONG)( ( wcslen( WszUtilImagePath() ) + 1 ) * sizeof( WCHAR ) ) );
                Assert( error == ERROR_SUCCESS );
            }
            cbData = cbDataMax;
            if (    pfnRegQueryValueExW(    hkeyImage,
                                            L"CategoryMessageFile",
                                            0,
                                            &dwType,
                                            LPBYTE(rgbData),
                                            &cbData ) != ERROR_SUCCESS ||
                    dwType != REG_EXPAND_SZ ||
                    wcscmp( rgbData, WszUtilImagePath() ) ||
                    cbData != ( wcslen( WszUtilImagePath() ) + 1 ) * sizeof( WCHAR ) )
            {
                error = pfnRegSetValueExW(  hkeyImage,
                                                L"CategoryMessageFile",
                                                0,
                                                REG_EXPAND_SZ,
                                                LPBYTE( WszUtilImagePath() ),
                                                (ULONG)( ( wcslen( WszUtilImagePath() ) + 1 ) * sizeof( WCHAR ) ) );
                Assert( error == ERROR_SUCCESS );
            }
            Data = MAC_CATEGORY - 1;
            cbData = cbDataMax;
            if (    pfnRegQueryValueExW(    hkeyImage,
                                            L"CategoryCount",
                                            0,
                                            &dwType,
                                            LPBYTE(rgbData),
                                            &cbData ) != ERROR_SUCCESS ||
                    dwType != REG_DWORD ||
                    memcmp( (BYTE*)rgbData, &Data, sizeof( Data ) ) ||
                    cbData != sizeof( Data ) )
            {
                error = pfnRegSetValueExW(  hkeyImage,
                                                L"CategoryCount",
                                                0,
                                                REG_DWORD,
                                                LPBYTE( &Data ),
                                                sizeof( Data ) );
                Assert( error == ERROR_SUCCESS );
            }
            Data = EVENTLOG_INFORMATION_TYPE | EVENTLOG_WARNING_TYPE | EVENTLOG_ERROR_TYPE;
            cbData = cbDataMax;
            if (    pfnRegQueryValueExW(    hkeyImage,
                                            L"TypesSupported",
                                            0,
                                            &dwType,
                                            LPBYTE(rgbData),
                                            &cbData ) != ERROR_SUCCESS ||
                    dwType != REG_DWORD ||
                    memcmp( (BYTE*)rgbData, &Data, sizeof( Data ) ) ||
                    cbData != sizeof( Data ) )
            {
                error = pfnRegSetValueExW(  hkeyImage,
                                                L"TypesSupported",
                                                0,
                                                REG_DWORD,
                                                LPBYTE( &Data ),
                                                sizeof( Data ) );
                Assert( error == ERROR_SUCCESS );
            }
            error = pfnRegCloseKey( hkeyImage );
            Assert( error == ERROR_SUCCESS );
        }
    }
#endif
#endif
}


void OSEventTerm()
{
}


ERR ErrOSEventInit()
{

    return JET_errSuccess;
}

