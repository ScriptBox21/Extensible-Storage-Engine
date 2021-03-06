// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#include "ese_common.hxx"
#include "esetest_bounce.hxx"
#include <stdlib.h>
#include <strsafe.h>
#include <windows.h>

JET_ERR
BounceJetInit(
    JET_INSTANCE *pinstance
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetInit ) (  JET_INSTANCE *pinstance );

    static PFN_JetInit pfnJetInit = NULL;

    if ( NULL == pfnJetInit )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetInit = ( PFN_JetInit ) ( GetProcAddress( hEseDll, "JetInit" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetInit )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetInit", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetInit)( pinstance );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetInit2(
    JET_INSTANCE *pinstance,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetInit2 ) (  JET_INSTANCE *pinstance, JET_GRBIT grbit  );

    static PFN_JetInit2 pfnJetInit2 = NULL;

    if ( NULL == pfnJetInit2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetInit2 = ( PFN_JetInit2 ) ( GetProcAddress( hEseDll, "JetInit2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetInit2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetInit2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetInit2)( pinstance, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetInstanceMiscInfo(
    JET_INSTANCE    instance,
    void *          pvResult,
    unsigned long       cbMax,
    unsigned long       InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetInstanceMiscInfo ) ( 
    JET_INSTANCE    instance,
    void *          pvResult,
    unsigned long       cbMax,
    unsigned long       InfoLevel  );

    static PFN_JetGetInstanceMiscInfo pfnJetGetInstanceMiscInfo = NULL;

    if ( NULL == pfnJetGetInstanceMiscInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetInstanceMiscInfo = ( PFN_JetGetInstanceMiscInfo ) ( GetProcAddress( hEseDll, "JetGetInstanceMiscInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetInstanceMiscInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetInstanceMiscInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetInstanceMiscInfo)( instance, pvResult, cbMax, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetTerm(
    JET_INSTANCE instance
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetTerm ) (  JET_INSTANCE instance  );

    static PFN_JetTerm pfnJetTerm = NULL;

    if ( NULL == pfnJetTerm )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetTerm = ( PFN_JetTerm ) ( GetProcAddress( hEseDll, "JetTerm" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetTerm )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetTerm", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetTerm)( instance );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetTerm2(
    JET_INSTANCE instance,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetTerm2 ) (  JET_INSTANCE instance, JET_GRBIT grbit  );

    static PFN_JetTerm2 pfnJetTerm2 = NULL;

    if ( NULL == pfnJetTerm2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetTerm2 = ( PFN_JetTerm2 ) ( GetProcAddress( hEseDll, "JetTerm2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetTerm2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetTerm2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetTerm2)( instance, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetStopService(
    
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetStopService ) (  );

    static PFN_JetStopService pfnJetStopService = NULL;

    if ( NULL == pfnJetStopService )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetStopService = ( PFN_JetStopService ) ( GetProcAddress( hEseDll, "JetStopService" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetStopService )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetStopService", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetStopService)(  );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetStopServiceInstance(
    JET_INSTANCE instance
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetStopServiceInstance ) (  JET_INSTANCE instance  );

    static PFN_JetStopServiceInstance pfnJetStopServiceInstance = NULL;

    if ( NULL == pfnJetStopServiceInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetStopServiceInstance = ( PFN_JetStopServiceInstance ) ( GetProcAddress( hEseDll, "JetStopServiceInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetStopServiceInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetStopServiceInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetStopServiceInstance)( instance );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetStopServiceInstance2(
    JET_INSTANCE instance,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetStopServiceInstance2 ) (  JET_INSTANCE instance, JET_GRBIT grbit  );

    static PFN_JetStopServiceInstance2 pfnJetStopServiceInstance2 = NULL;

    if ( NULL == pfnJetStopServiceInstance2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetStopServiceInstance2 = ( PFN_JetStopServiceInstance2 ) ( GetProcAddress( hEseDll, "JetStopServiceInstance2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetStopServiceInstance2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetStopServiceInstance2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetStopServiceInstance2)( instance, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetStopBackup(
    
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetStopBackup ) (  );

    static PFN_JetStopBackup pfnJetStopBackup = NULL;

    if ( NULL == pfnJetStopBackup )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetStopBackup = ( PFN_JetStopBackup ) ( GetProcAddress( hEseDll, "JetStopBackup" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetStopBackup )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetStopBackup", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetStopBackup)(  );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetStopBackupInstance(
    JET_INSTANCE instance
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetStopBackupInstance ) (  JET_INSTANCE instance  );

    static PFN_JetStopBackupInstance pfnJetStopBackupInstance = NULL;

    if ( NULL == pfnJetStopBackupInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetStopBackupInstance = ( PFN_JetStopBackupInstance ) ( GetProcAddress( hEseDll, "JetStopBackupInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetStopBackupInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetStopBackupInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetStopBackupInstance)( instance );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetSessionParameter(
    JET_SESID           sesid,
    unsigned long       sesparamid,
    void *              pvParam,
    unsigned long       cbParam
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetSessionParameter ) ( 
    JET_SESID           sesid,
    unsigned long       sesparamid,
    void *              pvParam,
    unsigned long       cbParam  );

    static PFN_JetSetSessionParameter pfnJetSetSessionParameter = NULL;

    if ( NULL == pfnJetSetSessionParameter )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetSessionParameter = ( PFN_JetSetSessionParameter ) ( GetProcAddress( hEseDll, "JetSetSessionParameter" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetSessionParameter )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetSessionParameter", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetSessionParameter)( sesid, sesparamid, pvParam, cbParam );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetResourceParam(
    JET_INSTANCE    instance,
    JET_RESOPER     resoper,
    JET_RESID       resid,
    JET_API_PTR     ulParam
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetResourceParam ) ( 
    JET_INSTANCE    instance,
    JET_RESOPER     resoper,
    JET_RESID       resid,
    JET_API_PTR     ulParam  );

    static PFN_JetSetResourceParam pfnJetSetResourceParam = NULL;

    if ( NULL == pfnJetSetResourceParam )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetResourceParam = ( PFN_JetSetResourceParam ) ( GetProcAddress( hEseDll, "JetSetResourceParam" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetResourceParam )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetResourceParam", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetResourceParam)( instance, resoper, resid, ulParam );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetResourceParam(
    JET_INSTANCE    instance,
    JET_RESOPER     resoper,
    JET_RESID       resid,
    JET_API_PTR     *pulParam
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetResourceParam ) ( 
    JET_INSTANCE    instance,
    JET_RESOPER     resoper,
    JET_RESID       resid,
    JET_API_PTR     *pulParam  );

    static PFN_JetGetResourceParam pfnJetGetResourceParam = NULL;

    if ( NULL == pfnJetGetResourceParam )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetResourceParam = ( PFN_JetGetResourceParam ) ( GetProcAddress( hEseDll, "JetGetResourceParam" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetResourceParam )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetResourceParam", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetResourceParam)( instance, resoper, resid, pulParam );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetResetCounter(
    JET_SESID sesid,
    long CounterType
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetResetCounter ) (  JET_SESID sesid, long CounterType  );

    static PFN_JetResetCounter pfnJetResetCounter = NULL;

    if ( NULL == pfnJetResetCounter )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetResetCounter = ( PFN_JetResetCounter ) ( GetProcAddress( hEseDll, "JetResetCounter" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetResetCounter )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetResetCounter", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetResetCounter)( sesid, CounterType );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetCounter(
    JET_SESID sesid,
    long CounterType,
    long *plValue
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetCounter ) (  JET_SESID sesid, long CounterType, long *plValue  );

    static PFN_JetGetCounter pfnJetGetCounter = NULL;

    if ( NULL == pfnJetGetCounter )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetCounter = ( PFN_JetGetCounter ) ( GetProcAddress( hEseDll, "JetGetCounter" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetCounter )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetCounter", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetCounter)( sesid, CounterType, plValue );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetThreadStats(
    __out_bcount(cbMax) void*           pvResult,
    unsigned long   cbMax
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetThreadStats ) ( 
    __out_bcount(cbMax) void*           pvResult,
    unsigned long   cbMax  );

    static PFN_JetGetThreadStats pfnJetGetThreadStats = NULL;

    if ( NULL == pfnJetGetThreadStats )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetThreadStats = ( PFN_JetGetThreadStats ) ( GetProcAddress( hEseDll, "JetGetThreadStats" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetThreadStats )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetThreadStats", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetThreadStats)( pvResult, cbMax );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDupSession(
    JET_SESID sesid,
    JET_SESID *psesid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDupSession ) (  JET_SESID sesid, JET_SESID *psesid  );

    static PFN_JetDupSession pfnJetDupSession = NULL;

    if ( NULL == pfnJetDupSession )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDupSession = ( PFN_JetDupSession ) ( GetProcAddress( hEseDll, "JetDupSession" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDupSession )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDupSession", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDupSession)( sesid, psesid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetEndSession(
    JET_SESID sesid,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetEndSession ) (  JET_SESID sesid, JET_GRBIT grbit  );

    static PFN_JetEndSession pfnJetEndSession = NULL;

    if ( NULL == pfnJetEndSession )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetEndSession = ( PFN_JetEndSession ) ( GetProcAddress( hEseDll, "JetEndSession" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetEndSession )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetEndSession", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetEndSession)( sesid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetSessionInfo(
    JET_SESID           sesid,
    __out_bcount(cbMax) void *  pvResult,
    const unsigned long cbMax,
    const unsigned long ulInfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetSessionInfo ) ( 
    JET_SESID           sesid,
    __out_bcount(cbMax) void *  pvResult,
    const unsigned long cbMax,
    const unsigned long ulInfoLevel  );

    static PFN_JetGetSessionInfo pfnJetGetSessionInfo = NULL;

    if ( NULL == pfnJetGetSessionInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetSessionInfo = ( PFN_JetGetSessionInfo ) ( GetProcAddress( hEseDll, "JetGetSessionInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetSessionInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetSessionInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetSessionInfo)( sesid, pvResult, cbMax, ulInfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetVersion(
    JET_SESID sesid,
    unsigned long *pwVersion
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetVersion ) (  JET_SESID sesid, unsigned long *pwVersion  );

    static PFN_JetGetVersion pfnJetGetVersion = NULL;

    if ( NULL == pfnJetGetVersion )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetVersion = ( PFN_JetGetVersion ) ( GetProcAddress( hEseDll, "JetGetVersion" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetVersion )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetVersion", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetVersion)( sesid, pwVersion );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetIdle(
    JET_SESID sesid,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetIdle ) (  JET_SESID sesid, JET_GRBIT grbit  );

    static PFN_JetIdle pfnJetIdle = NULL;

    if ( NULL == pfnJetIdle )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetIdle = ( PFN_JetIdle ) ( GetProcAddress( hEseDll, "JetIdle" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetIdle )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetIdle", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetIdle)( sesid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetObjectInfo(
    JET_SESID       sesid,
    JET_DBID        dbid,
    JET_OBJTYP      objtyp,
    const char      *szContainerName,
    const char      *szObjectName,
    __out_bcount(cbMax) void *  pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetObjectInfo ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    JET_OBJTYP      objtyp,
    const char      *szContainerName,
    const char      *szObjectName,
    __out_bcount(cbMax) void *  pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel  );

    static PFN_JetGetObjectInfo pfnJetGetObjectInfo = NULL;

    if ( NULL == pfnJetGetObjectInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetObjectInfo = ( PFN_JetGetObjectInfo ) ( GetProcAddress( hEseDll, "JetGetObjectInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetObjectInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetObjectInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetObjectInfo)( sesid, dbid, objtyp, szContainerName, szObjectName, pvResult, cbMax, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetTableInfo(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __out_bcount(cbMax) void *  pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetTableInfo ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __out_bcount(cbMax) void *  pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel  );

    static PFN_JetGetTableInfo pfnJetGetTableInfo = NULL;

    if ( NULL == pfnJetGetTableInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetTableInfo = ( PFN_JetGetTableInfo ) ( GetProcAddress( hEseDll, "JetGetTableInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetTableInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetTableInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetTableInfo)( sesid, tableid, pvResult, cbMax, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetPageInfo(
    __in_bcount(cbData)         const void *    pvPages,
    unsigned long   cbData,
    __inout_bcount(cbPageInfo)  JET_PAGEINFO *  rgPageInfo,
    unsigned long   cbPageInfo,
    JET_GRBIT       grbit,
    unsigned long   ulInfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetPageInfo ) ( 
    __in_bcount(cbData)         const void *    pvPages,
                                unsigned long   cbData,
    __inout_bcount(cbPageInfo)  JET_PAGEINFO *  rgPageInfo,
                                unsigned long   cbPageInfo,
                                JET_GRBIT       grbit,
                                unsigned long   ulInfoLevel  );

    static PFN_JetGetPageInfo pfnJetGetPageInfo = NULL;

    if ( NULL == pfnJetGetPageInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetPageInfo = ( PFN_JetGetPageInfo ) ( GetProcAddress( hEseDll, "JetGetPageInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetPageInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetPageInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetPageInfo)( pvPages, cbData, rgPageInfo, cbPageInfo, grbit, ulInfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetPageInfo2(
    __in_bcount(cbData)         const void *    pvPages,
    unsigned long   cbData,
    __inout_bcount(cbPageInfo)  JET_PAGEINFO *  rgPageInfo,
    unsigned long   cbPageInfo,
    JET_GRBIT       grbit,
    unsigned long   ulInfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetPageInfo2 ) ( 
    __in_bcount(cbData)         const void *    pvPages,
                                unsigned long   cbData,
    __inout_bcount(cbPageInfo)  JET_PAGEINFO *  rgPageInfo,
                                unsigned long   cbPageInfo,
                                JET_GRBIT       grbit,
                                unsigned long   ulInfoLevel  );

    static PFN_JetGetPageInfo2 pfnJetGetPageInfo2 = NULL;

    if ( NULL == pfnJetGetPageInfo2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetPageInfo2 = ( PFN_JetGetPageInfo2 ) ( GetProcAddress( hEseDll, "JetGetPageInfo2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetPageInfo2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetPageInfo2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetPageInfo2)( pvPages, cbData, rgPageInfo, cbPageInfo, grbit, ulInfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetTableColumnInfo(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szColumnName,
    __out_bcount(cbMax) void *  pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetTableColumnInfo ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szColumnName,
    __out_bcount(cbMax) void *  pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel  );

    static PFN_JetGetTableColumnInfo pfnJetGetTableColumnInfo = NULL;

    if ( NULL == pfnJetGetTableColumnInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetTableColumnInfo = ( PFN_JetGetTableColumnInfo ) ( GetProcAddress( hEseDll, "JetGetTableColumnInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetTableColumnInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetTableColumnInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetTableColumnInfo)( sesid, tableid, szColumnName, pvResult, cbMax, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetColumnInfo(
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    const char      *szColumnName,
    __out_bcount(cbMax) void *  pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetColumnInfo ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    const char      *szColumnName,
    __out_bcount(cbMax) void *  pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel  );

    static PFN_JetGetColumnInfo pfnJetGetColumnInfo = NULL;

    if ( NULL == pfnJetGetColumnInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetColumnInfo = ( PFN_JetGetColumnInfo ) ( GetProcAddress( hEseDll, "JetGetColumnInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetColumnInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetColumnInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetColumnInfo)( sesid, dbid, szTableName, szColumnName, pvResult, cbMax, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetTableIndexInfo(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szIndexName,
    __out_bcount(cbResult) void         *pvResult,
    unsigned long   cbResult,
    unsigned long   InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetTableIndexInfo ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szIndexName,
    __out_bcount(cbResult) void         *pvResult,
    unsigned long   cbResult,
    unsigned long   InfoLevel  );

    static PFN_JetGetTableIndexInfo pfnJetGetTableIndexInfo = NULL;

    if ( NULL == pfnJetGetTableIndexInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetTableIndexInfo = ( PFN_JetGetTableIndexInfo ) ( GetProcAddress( hEseDll, "JetGetTableIndexInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetTableIndexInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetTableIndexInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetTableIndexInfo)( sesid, tableid, szIndexName, pvResult, cbResult, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetIndexInfo(
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    const char      *szIndexName,
    __out_bcount(cbResult) void         *pvResult,
    unsigned long   cbResult,
    unsigned long   InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetIndexInfo ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    const char      *szIndexName,
    __out_bcount(cbResult) void         *pvResult,
    unsigned long   cbResult,
    unsigned long   InfoLevel  );

    static PFN_JetGetIndexInfo pfnJetGetIndexInfo = NULL;

    if ( NULL == pfnJetGetIndexInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetIndexInfo = ( PFN_JetGetIndexInfo ) ( GetProcAddress( hEseDll, "JetGetIndexInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetIndexInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetIndexInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetIndexInfo)( sesid, dbid, szTableName, szIndexName, pvResult, cbResult, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetBeginTransaction(
    JET_SESID sesid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetBeginTransaction ) (  JET_SESID sesid  );

    static PFN_JetBeginTransaction pfnJetBeginTransaction = NULL;

    if ( NULL == pfnJetBeginTransaction )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetBeginTransaction = ( PFN_JetBeginTransaction ) ( GetProcAddress( hEseDll, "JetBeginTransaction" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetBeginTransaction )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetBeginTransaction", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetBeginTransaction)( sesid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetBeginTransaction2(
    JET_SESID sesid,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetBeginTransaction2 ) (  JET_SESID sesid, JET_GRBIT grbit  );

    static PFN_JetBeginTransaction2 pfnJetBeginTransaction2 = NULL;

    if ( NULL == pfnJetBeginTransaction2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetBeginTransaction2 = ( PFN_JetBeginTransaction2 ) ( GetProcAddress( hEseDll, "JetBeginTransaction2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetBeginTransaction2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetBeginTransaction2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetBeginTransaction2)( sesid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetPrepareToCommitTransaction(
    JET_SESID       sesid,
    const void      * pvData,
    unsigned long   cbData,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetPrepareToCommitTransaction ) ( 
    JET_SESID       sesid,
    const void      * pvData,
    unsigned long   cbData,
    JET_GRBIT       grbit  );

    static PFN_JetPrepareToCommitTransaction pfnJetPrepareToCommitTransaction = NULL;

    if ( NULL == pfnJetPrepareToCommitTransaction )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetPrepareToCommitTransaction = ( PFN_JetPrepareToCommitTransaction ) ( GetProcAddress( hEseDll, "JetPrepareToCommitTransaction" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetPrepareToCommitTransaction )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetPrepareToCommitTransaction", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetPrepareToCommitTransaction)( sesid, pvData, cbData, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCommitTransaction(
    JET_SESID sesid,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCommitTransaction ) (  JET_SESID sesid, JET_GRBIT grbit  );

    static PFN_JetCommitTransaction pfnJetCommitTransaction = NULL;

    if ( NULL == pfnJetCommitTransaction )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCommitTransaction = ( PFN_JetCommitTransaction ) ( GetProcAddress( hEseDll, "JetCommitTransaction" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCommitTransaction )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCommitTransaction", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCommitTransaction)( sesid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRollback(
    JET_SESID sesid,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRollback ) (  JET_SESID sesid, JET_GRBIT grbit  );

    static PFN_JetRollback pfnJetRollback = NULL;

    if ( NULL == pfnJetRollback )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRollback = ( PFN_JetRollback ) ( GetProcAddress( hEseDll, "JetRollback" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRollback )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRollback", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRollback)( sesid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetDatabaseInfo(
    JET_SESID       sesid,
    JET_DBID        dbid,
    void            *pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetDatabaseInfo ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    void            *pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel  );

    static PFN_JetGetDatabaseInfo pfnJetGetDatabaseInfo = NULL;

    if ( NULL == pfnJetGetDatabaseInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetDatabaseInfo = ( PFN_JetGetDatabaseInfo ) ( GetProcAddress( hEseDll, "JetGetDatabaseInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetDatabaseInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetDatabaseInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetDatabaseInfo)( sesid, dbid, pvResult, cbMax, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCloseDatabase(
    JET_SESID       sesid,
    JET_DBID        dbid,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCloseDatabase ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    JET_GRBIT       grbit  );

    static PFN_JetCloseDatabase pfnJetCloseDatabase = NULL;

    if ( NULL == pfnJetCloseDatabase )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCloseDatabase = ( PFN_JetCloseDatabase ) ( GetProcAddress( hEseDll, "JetCloseDatabase" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCloseDatabase )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCloseDatabase", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCloseDatabase)( sesid, dbid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetTableInfo(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const void      *pvParam,
    unsigned long   cbParam,
    unsigned long   InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetTableInfo ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const void      *pvParam,
    unsigned long   cbParam,
    unsigned long   InfoLevel  );

    static PFN_JetSetTableInfo pfnJetSetTableInfo = NULL;

    if ( NULL == pfnJetSetTableInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetTableInfo = ( PFN_JetSetTableInfo ) ( GetProcAddress( hEseDll, "JetSetTableInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetTableInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetTableInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetTableInfo)( sesid, tableid, pvParam, cbParam, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetTableSequential(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetTableSequential ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_GRBIT       grbit  );

    static PFN_JetSetTableSequential pfnJetSetTableSequential = NULL;

    if ( NULL == pfnJetSetTableSequential )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetTableSequential = ( PFN_JetSetTableSequential ) ( GetProcAddress( hEseDll, "JetSetTableSequential" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetTableSequential )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetTableSequential", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetTableSequential)( sesid, tableid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetResetTableSequential(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetResetTableSequential ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_GRBIT       grbit  );

    static PFN_JetResetTableSequential pfnJetResetTableSequential = NULL;

    if ( NULL == pfnJetResetTableSequential )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetResetTableSequential = ( PFN_JetResetTableSequential ) ( GetProcAddress( hEseDll, "JetResetTableSequential" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetResetTableSequential )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetResetTableSequential", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetResetTableSequential)( sesid, tableid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCloseTable(
    JET_SESID sesid,
    JET_TABLEID tableid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCloseTable ) (  JET_SESID sesid, JET_TABLEID tableid  );

    static PFN_JetCloseTable pfnJetCloseTable = NULL;

    if ( NULL == pfnJetCloseTable )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCloseTable = ( PFN_JetCloseTable ) ( GetProcAddress( hEseDll, "JetCloseTable" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCloseTable )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCloseTable", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCloseTable)( sesid, tableid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDelete(
    JET_SESID sesid,
    JET_TABLEID tableid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDelete ) (  JET_SESID sesid, JET_TABLEID tableid  );

    static PFN_JetDelete pfnJetDelete = NULL;

    if ( NULL == pfnJetDelete )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDelete = ( PFN_JetDelete ) ( GetProcAddress( hEseDll, "JetDelete" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDelete )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDelete", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDelete)( sesid, tableid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetUpdate(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    void            *pvBookmark,
    unsigned long   cbBookmark,
    unsigned long   *pcbActual
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetUpdate ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    void            *pvBookmark,
    unsigned long   cbBookmark,
    unsigned long   *pcbActual );

    static PFN_JetUpdate pfnJetUpdate = NULL;

    if ( NULL == pfnJetUpdate )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetUpdate = ( PFN_JetUpdate ) ( GetProcAddress( hEseDll, "JetUpdate" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetUpdate )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetUpdate", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetUpdate)( sesid, tableid, pvBookmark, cbBookmark, pcbActual );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetUpdate2(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    void            *pvBookmark,
    unsigned long   cbBookmark,
    unsigned long   *pcbActual,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetUpdate2 ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    void            *pvBookmark,
    unsigned long   cbBookmark,
    unsigned long   *pcbActual,
    const JET_GRBIT grbit  );

    static PFN_JetUpdate2 pfnJetUpdate2 = NULL;

    if ( NULL == pfnJetUpdate2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetUpdate2 = ( PFN_JetUpdate2 ) ( GetProcAddress( hEseDll, "JetUpdate2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetUpdate2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetUpdate2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetUpdate2)( sesid, tableid, pvBookmark, cbBookmark, pcbActual, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetEscrowUpdate(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_COLUMNID    columnid,
    void            *pv,
    unsigned long   cbMax,
    void            *pvOld,
    unsigned long   cbOldMax,
    unsigned long   *pcbOldActual,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetEscrowUpdate ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_COLUMNID    columnid,
    void            *pv,
    unsigned long   cbMax,
    void            *pvOld,
    unsigned long   cbOldMax,
    unsigned long   *pcbOldActual,
    JET_GRBIT       grbit  );

    static PFN_JetEscrowUpdate pfnJetEscrowUpdate = NULL;

    if ( NULL == pfnJetEscrowUpdate )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetEscrowUpdate = ( PFN_JetEscrowUpdate ) ( GetProcAddress( hEseDll, "JetEscrowUpdate" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetEscrowUpdate )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetEscrowUpdate", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetEscrowUpdate)( sesid, tableid, columnid, pv, cbMax, pvOld, cbOldMax, pcbOldActual, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRetrieveColumn(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_COLUMNID    columnid,
    void            *pvData,
    unsigned long   cbData,
    unsigned long   *pcbActual,
    JET_GRBIT       grbit,
    JET_RETINFO     *pretinfo
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRetrieveColumn ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_COLUMNID    columnid,
    void            *pvData,
    unsigned long   cbData,
    unsigned long   *pcbActual,
    JET_GRBIT       grbit,
    JET_RETINFO     *pretinfo  );

    static PFN_JetRetrieveColumn pfnJetRetrieveColumn = NULL;

    if ( NULL == pfnJetRetrieveColumn )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRetrieveColumn = ( PFN_JetRetrieveColumn ) ( GetProcAddress( hEseDll, "JetRetrieveColumn" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRetrieveColumn )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRetrieveColumn", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRetrieveColumn)( sesid, tableid, columnid, pvData, cbData, pcbActual, grbit, pretinfo );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRetrieveColumns(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_RETRIEVECOLUMN  *pretrievecolumn,
    unsigned long   cretrievecolumn
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRetrieveColumns ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_RETRIEVECOLUMN  *pretrievecolumn,
    unsigned long   cretrievecolumn  );

    static PFN_JetRetrieveColumns pfnJetRetrieveColumns = NULL;

    if ( NULL == pfnJetRetrieveColumns )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRetrieveColumns = ( PFN_JetRetrieveColumns ) ( GetProcAddress( hEseDll, "JetRetrieveColumns" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRetrieveColumns )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRetrieveColumns", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRetrieveColumns)( sesid, tableid, pretrievecolumn, cretrievecolumn );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetEnumerateColumns(
    JET_SESID               sesid,
    JET_TABLEID             tableid,
    unsigned long           cEnumColumnId,
    JET_ENUMCOLUMNID*       rgEnumColumnId,
    unsigned long*          pcEnumColumn,
    JET_ENUMCOLUMN**        prgEnumColumn,
    JET_PFNREALLOC          pfnRealloc,
    void*                   pvReallocContext,
    unsigned long           cbDataMost,
    JET_GRBIT               grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetEnumerateColumns ) ( 
    JET_SESID               sesid,
    JET_TABLEID             tableid,
    unsigned long           cEnumColumnId,
    JET_ENUMCOLUMNID*       rgEnumColumnId,
    unsigned long*          pcEnumColumn,
    JET_ENUMCOLUMN**        prgEnumColumn,
    JET_PFNREALLOC          pfnRealloc,
    void*                   pvReallocContext,
    unsigned long           cbDataMost,
    JET_GRBIT               grbit  );

    static PFN_JetEnumerateColumns pfnJetEnumerateColumns = NULL;

    if ( NULL == pfnJetEnumerateColumns )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetEnumerateColumns = ( PFN_JetEnumerateColumns ) ( GetProcAddress( hEseDll, "JetEnumerateColumns" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetEnumerateColumns )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetEnumerateColumns", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetEnumerateColumns)( sesid, tableid, cEnumColumnId, rgEnumColumnId, pcEnumColumn, prgEnumColumn, pfnRealloc, pvReallocContext, cbDataMost, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRetrieveTaggedColumnList(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    unsigned long   *pcColumns,
    void            *pvData,
    unsigned long   cbData,
    JET_COLUMNID    columnidStart,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRetrieveTaggedColumnList ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    unsigned long   *pcColumns,
    void            *pvData,
    unsigned long   cbData,
    JET_COLUMNID    columnidStart,
    JET_GRBIT       grbit  );

    static PFN_JetRetrieveTaggedColumnList pfnJetRetrieveTaggedColumnList = NULL;

    if ( NULL == pfnJetRetrieveTaggedColumnList )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRetrieveTaggedColumnList = ( PFN_JetRetrieveTaggedColumnList ) ( GetProcAddress( hEseDll, "JetRetrieveTaggedColumnList" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRetrieveTaggedColumnList )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRetrieveTaggedColumnList", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRetrieveTaggedColumnList)( sesid, tableid, pcColumns, pvData, cbData, columnidStart, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetRecordSize(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_RECSIZE *   precsize,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetRecordSize ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_RECSIZE *   precsize,
    const JET_GRBIT grbit  );

    static PFN_JetGetRecordSize pfnJetGetRecordSize = NULL;

    if ( NULL == pfnJetGetRecordSize )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetRecordSize = ( PFN_JetGetRecordSize ) ( GetProcAddress( hEseDll, "JetGetRecordSize" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetRecordSize )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetRecordSize", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetRecordSize)( sesid, tableid, precsize, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetPrepareUpdate(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    unsigned long   prep
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetPrepareUpdate ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    unsigned long   prep  );

    static PFN_JetPrepareUpdate pfnJetPrepareUpdate = NULL;

    if ( NULL == pfnJetPrepareUpdate )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetPrepareUpdate = ( PFN_JetPrepareUpdate ) ( GetProcAddress( hEseDll, "JetPrepareUpdate" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetPrepareUpdate )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetPrepareUpdate", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetPrepareUpdate)( sesid, tableid, prep );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetRecordPosition(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_RECPOS      *precpos,
    unsigned long   cbRecpos
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetRecordPosition ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_RECPOS      *precpos,
    unsigned long   cbRecpos  );

    static PFN_JetGetRecordPosition pfnJetGetRecordPosition = NULL;

    if ( NULL == pfnJetGetRecordPosition )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetRecordPosition = ( PFN_JetGetRecordPosition ) ( GetProcAddress( hEseDll, "JetGetRecordPosition" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetRecordPosition )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetRecordPosition", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetRecordPosition)( sesid, tableid, precpos, cbRecpos );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGotoPosition(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_RECPOS      *precpos
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGotoPosition ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_RECPOS      *precpos  );

    static PFN_JetGotoPosition pfnJetGotoPosition = NULL;

    if ( NULL == pfnJetGotoPosition )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGotoPosition = ( PFN_JetGotoPosition ) ( GetProcAddress( hEseDll, "JetGotoPosition" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGotoPosition )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGotoPosition", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGotoPosition)( sesid, tableid, precpos );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetCursorInfo(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __out_bcount(cbMax) void            *pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetCursorInfo ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __out_bcount(cbMax) void            *pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel  );

    static PFN_JetGetCursorInfo pfnJetGetCursorInfo = NULL;

    if ( NULL == pfnJetGetCursorInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetCursorInfo = ( PFN_JetGetCursorInfo ) ( GetProcAddress( hEseDll, "JetGetCursorInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetCursorInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetCursorInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetCursorInfo)( sesid, tableid, pvResult, cbMax, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDupCursor(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_TABLEID     *ptableid,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDupCursor ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_TABLEID     *ptableid,
    JET_GRBIT       grbit  );

    static PFN_JetDupCursor pfnJetDupCursor = NULL;

    if ( NULL == pfnJetDupCursor )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDupCursor = ( PFN_JetDupCursor ) ( GetProcAddress( hEseDll, "JetDupCursor" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDupCursor )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDupCursor", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDupCursor)( sesid, tableid, ptableid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetMove(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    long            cRow,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetMove ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    long            cRow,
    JET_GRBIT       grbit  );

    static PFN_JetMove pfnJetMove = NULL;

    if ( NULL == pfnJetMove )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetMove = ( PFN_JetMove ) ( GetProcAddress( hEseDll, "JetMove" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetMove )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetMove", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetMove)( sesid, tableid, cRow, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetLock(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetLock ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_GRBIT       grbit  );

    static PFN_JetGetLock pfnJetGetLock = NULL;

    if ( NULL == pfnJetGetLock )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetLock = ( PFN_JetGetLock ) ( GetProcAddress( hEseDll, "JetGetLock" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetLock )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetLock", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetLock)( sesid, tableid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetMakeKey(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __in_bcount(cbData) const void      *pvData,
    unsigned long   cbData,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetMakeKey ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __in_bcount(cbData) const void      *pvData,
    unsigned long   cbData,
    JET_GRBIT       grbit  );

    static PFN_JetMakeKey pfnJetMakeKey = NULL;

    if ( NULL == pfnJetMakeKey )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetMakeKey = ( PFN_JetMakeKey ) ( GetProcAddress( hEseDll, "JetMakeKey" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetMakeKey )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetMakeKey", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetMakeKey)( sesid, tableid, pvData, cbData, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSeek(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSeek ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_GRBIT       grbit  );

    static PFN_JetSeek pfnJetSeek = NULL;

    if ( NULL == pfnJetSeek )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSeek = ( PFN_JetSeek ) ( GetProcAddress( hEseDll, "JetSeek" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSeek )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSeek", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSeek)( sesid, tableid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetBookmark(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __out_bcount_part_opt(cbMax,
    *pcbActual) void *          pvBookmark,
    unsigned long   cbMax,
    unsigned long * pcbActual
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetBookmark ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __out_bcount_part_opt(cbMax, *pcbActual) void *         pvBookmark,
    unsigned long   cbMax,
    unsigned long * pcbActual  );

    static PFN_JetGetBookmark pfnJetGetBookmark = NULL;

    if ( NULL == pfnJetGetBookmark )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetBookmark = ( PFN_JetGetBookmark ) ( GetProcAddress( hEseDll, "JetGetBookmark" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetBookmark )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetBookmark", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetBookmark)( sesid, tableid, pvBookmark, cbMax, pcbActual );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetSecondaryIndexBookmark(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __out_bcount_part(cbSecondaryKeyMax,
    *pcbSecondaryKeyActual) void *          pvSecondaryKey,
    unsigned long   cbSecondaryKeyMax,
    unsigned long * pcbSecondaryKeyActual,
    __out_bcount_part(cbPrimaryBookmarkMax,
    *pcbPrimaryKeyActual) void *            pvPrimaryBookmark,
    unsigned long   cbPrimaryBookmarkMax,
    unsigned long * pcbPrimaryKeyActual,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetSecondaryIndexBookmark ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __out_bcount_part(cbSecondaryKeyMax, *pcbSecondaryKeyActual) void *         pvSecondaryKey,
    unsigned long   cbSecondaryKeyMax,
    unsigned long * pcbSecondaryKeyActual,
    __out_bcount_part(cbPrimaryBookmarkMax, *pcbPrimaryKeyActual) void *            pvPrimaryBookmark,
    unsigned long   cbPrimaryBookmarkMax,
    unsigned long * pcbPrimaryKeyActual,
    const JET_GRBIT grbit  );

    static PFN_JetGetSecondaryIndexBookmark pfnJetGetSecondaryIndexBookmark = NULL;

    if ( NULL == pfnJetGetSecondaryIndexBookmark )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetSecondaryIndexBookmark = ( PFN_JetGetSecondaryIndexBookmark ) ( GetProcAddress( hEseDll, "JetGetSecondaryIndexBookmark" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetSecondaryIndexBookmark )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetSecondaryIndexBookmark", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetSecondaryIndexBookmark)( sesid, tableid, pvSecondaryKey, cbSecondaryKeyMax, pcbSecondaryKeyActual, pvPrimaryBookmark, cbPrimaryBookmarkMax, pcbPrimaryKeyActual, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDatabaseScan(
    JET_SESID       sesid,
    JET_DBID        dbid,
    unsigned long * pcSeconds,
    unsigned long   cmsecSleep,
    JET_CALLBACK    pfnCallback,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDatabaseScan ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    unsigned long * pcSeconds,
    unsigned long   cmsecSleep,
    JET_CALLBACK    pfnCallback,
    JET_GRBIT       grbit  );

    static PFN_JetDatabaseScan pfnJetDatabaseScan = NULL;

    if ( NULL == pfnJetDatabaseScan )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDatabaseScan = ( PFN_JetDatabaseScan ) ( GetProcAddress( hEseDll, "JetDatabaseScan" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDatabaseScan )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDatabaseScan", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDatabaseScan)( sesid, dbid, pcSeconds, cmsecSleep, pfnCallback, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetConvertDDL(
    JET_SESID       sesid,
    JET_DBID        dbid,
    JET_OPDDLCONV   convtyp,
    __out_bcount(cbData) void           *pvData,
    unsigned long   cbData
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetConvertDDL ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    JET_OPDDLCONV   convtyp,
    __out_bcount(cbData) void           *pvData,
    unsigned long   cbData  );

    static PFN_JetConvertDDL pfnJetConvertDDL = NULL;

    if ( NULL == pfnJetConvertDDL )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetConvertDDL = ( PFN_JetConvertDDL ) ( GetProcAddress( hEseDll, "JetConvertDDL" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetConvertDDL )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetConvertDDL", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetConvertDDL)( sesid, dbid, convtyp, pvData, cbData );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetMaxDatabaseSize(
    JET_SESID       sesid,
    JET_DBID        dbid,
    unsigned long   cpg,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetMaxDatabaseSize ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    unsigned long   cpg,
    JET_GRBIT       grbit  );

    static PFN_JetSetMaxDatabaseSize pfnJetSetMaxDatabaseSize = NULL;

    if ( NULL == pfnJetSetMaxDatabaseSize )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetMaxDatabaseSize = ( PFN_JetSetMaxDatabaseSize ) ( GetProcAddress( hEseDll, "JetSetMaxDatabaseSize" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetMaxDatabaseSize )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetMaxDatabaseSize", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetMaxDatabaseSize)( sesid, dbid, cpg, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetMaxDatabaseSize(
    JET_SESID       sesid,
    JET_DBID        dbid,
    unsigned long   * pcpg,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetMaxDatabaseSize ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    unsigned long   * pcpg,
    JET_GRBIT       grbit  );

    static PFN_JetGetMaxDatabaseSize pfnJetGetMaxDatabaseSize = NULL;

    if ( NULL == pfnJetGetMaxDatabaseSize )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetMaxDatabaseSize = ( PFN_JetGetMaxDatabaseSize ) ( GetProcAddress( hEseDll, "JetGetMaxDatabaseSize" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetMaxDatabaseSize )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetMaxDatabaseSize", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetMaxDatabaseSize)( sesid, dbid, pcpg, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetDatabaseSize(
    JET_SESID       sesid,
    const char      *szDatabaseName,
    unsigned long   cpg,
    unsigned long   *pcpgReal
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetDatabaseSize ) ( 
    JET_SESID       sesid,
    const char      *szDatabaseName,
    unsigned long   cpg,
    unsigned long   *pcpgReal  );

    static PFN_JetSetDatabaseSize pfnJetSetDatabaseSize = NULL;

    if ( NULL == pfnJetSetDatabaseSize )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetDatabaseSize = ( PFN_JetSetDatabaseSize ) ( GetProcAddress( hEseDll, "JetSetDatabaseSize" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetDatabaseSize )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetDatabaseSize", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetDatabaseSize)( sesid, szDatabaseName, cpg, pcpgReal );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGrowDatabase(
    JET_SESID       sesid,
    JET_DBID        dbid,
    unsigned long   cpg,
    unsigned long   *pcpgReal
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGrowDatabase ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    unsigned long   cpg,
    unsigned long   *pcpgReal  );

    static PFN_JetGrowDatabase pfnJetGrowDatabase = NULL;

    if ( NULL == pfnJetGrowDatabase )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGrowDatabase = ( PFN_JetGrowDatabase ) ( GetProcAddress( hEseDll, "JetGrowDatabase" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGrowDatabase )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGrowDatabase", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGrowDatabase)( sesid, dbid, cpg, pcpgReal );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetResizeDatabase(
    JET_SESID       sesid,
    JET_DBID        dbid,
    unsigned long   cpg,
    unsigned long   *pcpgActual,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetResizeDatabase ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    unsigned long   cpg,
    unsigned long   *pcpgActual,
    const JET_GRBIT grbit  );

    static PFN_JetResizeDatabase pfnJetResizeDatabase = NULL;

    if ( NULL == pfnJetResizeDatabase )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetResizeDatabase = ( PFN_JetResizeDatabase ) ( GetProcAddress( hEseDll, "JetResizeDatabase" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetResizeDatabase )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetResizeDatabase", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetResizeDatabase)( sesid, dbid, cpg, pcpgActual, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetSessionContext(
    JET_SESID       sesid,
    JET_API_PTR     ulContext
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetSessionContext ) ( 
    JET_SESID       sesid,
    JET_API_PTR     ulContext  );

    static PFN_JetSetSessionContext pfnJetSetSessionContext = NULL;

    if ( NULL == pfnJetSetSessionContext )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetSessionContext = ( PFN_JetSetSessionContext ) ( GetProcAddress( hEseDll, "JetSetSessionContext" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetSessionContext )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetSessionContext", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetSessionContext)( sesid, ulContext );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetResetSessionContext(
    JET_SESID       sesid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetResetSessionContext ) ( 
    JET_SESID       sesid  );

    static PFN_JetResetSessionContext pfnJetResetSessionContext = NULL;

    if ( NULL == pfnJetResetSessionContext )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetResetSessionContext = ( PFN_JetResetSessionContext ) ( GetProcAddress( hEseDll, "JetResetSessionContext" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetResetSessionContext )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetResetSessionContext", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetResetSessionContext)( sesid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDBUtilities(
    JET_DBUTIL *pdbutil
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDBUtilities ) (  JET_DBUTIL *pdbutil  );

    static PFN_JetDBUtilities pfnJetDBUtilities = NULL;

    if ( NULL == pfnJetDBUtilities )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDBUtilities = ( PFN_JetDBUtilities ) ( GetProcAddress( hEseDll, "JetDBUtilities" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDBUtilities )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDBUtilities", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDBUtilities)( pdbutil );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGotoBookmark(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __in_bcount(cbBookmark) void *          pvBookmark,
    unsigned long   cbBookmark
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGotoBookmark ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __in_bcount(cbBookmark) void *          pvBookmark,
    unsigned long   cbBookmark  );

    static PFN_JetGotoBookmark pfnJetGotoBookmark = NULL;

    if ( NULL == pfnJetGotoBookmark )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGotoBookmark = ( PFN_JetGotoBookmark ) ( GetProcAddress( hEseDll, "JetGotoBookmark" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGotoBookmark )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGotoBookmark", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGotoBookmark)( sesid, tableid, pvBookmark, cbBookmark );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGotoSecondaryIndexBookmark(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __in_bcount(cbSecondaryKey) void *          pvSecondaryKey,
    unsigned long   cbSecondaryKey,
    __in_bcount(cbPrimaryBookmark) void *           pvPrimaryBookmark,
    unsigned long   cbPrimaryBookmark,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGotoSecondaryIndexBookmark ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __in_bcount(cbSecondaryKey) void *          pvSecondaryKey,
    unsigned long   cbSecondaryKey,
    __in_bcount(cbPrimaryBookmark) void *           pvPrimaryBookmark,
    unsigned long   cbPrimaryBookmark,
    const JET_GRBIT grbit  );

    static PFN_JetGotoSecondaryIndexBookmark pfnJetGotoSecondaryIndexBookmark = NULL;

    if ( NULL == pfnJetGotoSecondaryIndexBookmark )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGotoSecondaryIndexBookmark = ( PFN_JetGotoSecondaryIndexBookmark ) ( GetProcAddress( hEseDll, "JetGotoSecondaryIndexBookmark" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGotoSecondaryIndexBookmark )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGotoSecondaryIndexBookmark", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGotoSecondaryIndexBookmark)( sesid, tableid, pvSecondaryKey, cbSecondaryKey, pvPrimaryBookmark, cbPrimaryBookmark, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetIntersectIndexes(
    JET_SESID sesid,
    __in_ecount(cindexrange) JET_INDEXRANGE * rgindexrange,
    unsigned long cindexrange,
    JET_RECORDLIST * precordlist,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetIntersectIndexes ) ( 
    JET_SESID sesid,
    __in_ecount(cindexrange) JET_INDEXRANGE * rgindexrange,
    unsigned long cindexrange,
    JET_RECORDLIST * precordlist,
    JET_GRBIT grbit  );

    static PFN_JetIntersectIndexes pfnJetIntersectIndexes = NULL;

    if ( NULL == pfnJetIntersectIndexes )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetIntersectIndexes = ( PFN_JetIntersectIndexes ) ( GetProcAddress( hEseDll, "JetIntersectIndexes" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetIntersectIndexes )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetIntersectIndexes", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetIntersectIndexes)( sesid, rgindexrange, cindexrange, precordlist, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetComputeStats(
    JET_SESID sesid,
    JET_TABLEID tableid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetComputeStats ) (  JET_SESID sesid, JET_TABLEID tableid  );

    static PFN_JetComputeStats pfnJetComputeStats = NULL;

    if ( NULL == pfnJetComputeStats )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetComputeStats = ( PFN_JetComputeStats ) ( GetProcAddress( hEseDll, "JetComputeStats" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetComputeStats )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetComputeStats", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetComputeStats)( sesid, tableid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOpenTempTable(
    JET_SESID sesid,
    __in_ecount(ccolumn) const JET_COLUMNDEF *prgcolumndef,
    unsigned long ccolumn,
    JET_GRBIT grbit,
    JET_TABLEID *ptableid,
    JET_COLUMNID *prgcolumnid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOpenTempTable ) ( 
    JET_SESID sesid,
    __in_ecount(ccolumn) const JET_COLUMNDEF *prgcolumndef,
    unsigned long ccolumn,
    JET_GRBIT grbit,
    JET_TABLEID *ptableid,
    JET_COLUMNID *prgcolumnid );

    static PFN_JetOpenTempTable pfnJetOpenTempTable = NULL;

    if ( NULL == pfnJetOpenTempTable )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOpenTempTable = ( PFN_JetOpenTempTable ) ( GetProcAddress( hEseDll, "JetOpenTempTable" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOpenTempTable )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOpenTempTable", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOpenTempTable)( sesid, prgcolumndef, ccolumn, grbit, ptableid, prgcolumnid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOpenTempTable2(
    JET_SESID           sesid,
    __in_ecount(ccolumn) const JET_COLUMNDEF    *prgcolumndef,
    unsigned long       ccolumn,
    unsigned long       lcid,
    JET_GRBIT           grbit,
    JET_TABLEID         *ptableid,
    JET_COLUMNID        *prgcolumnid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOpenTempTable2 ) ( 
    JET_SESID           sesid,
    __in_ecount(ccolumn) const JET_COLUMNDEF    *prgcolumndef,
    unsigned long       ccolumn,
    unsigned long       lcid,
    JET_GRBIT           grbit,
    JET_TABLEID         *ptableid,
    JET_COLUMNID        *prgcolumnid  );

    static PFN_JetOpenTempTable2 pfnJetOpenTempTable2 = NULL;

    if ( NULL == pfnJetOpenTempTable2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOpenTempTable2 = ( PFN_JetOpenTempTable2 ) ( GetProcAddress( hEseDll, "JetOpenTempTable2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOpenTempTable2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOpenTempTable2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOpenTempTable2)( sesid, prgcolumndef, ccolumn, lcid, grbit, ptableid, prgcolumnid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOpenTempTable3(
    JET_SESID           sesid,
    __in_ecount(ccolumn) const JET_COLUMNDEF    *prgcolumndef,
    unsigned long       ccolumn,
    JET_UNICODEINDEX    *pidxunicode,
    JET_GRBIT           grbit,
    JET_TABLEID         *ptableid,
    JET_COLUMNID        *prgcolumnid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOpenTempTable3 ) ( 
    JET_SESID           sesid,
    __in_ecount(ccolumn) const JET_COLUMNDEF    *prgcolumndef,
    unsigned long       ccolumn,
    JET_UNICODEINDEX    *pidxunicode,
    JET_GRBIT           grbit,
    JET_TABLEID         *ptableid,
    JET_COLUMNID        *prgcolumnid  );

    static PFN_JetOpenTempTable3 pfnJetOpenTempTable3 = NULL;

    if ( NULL == pfnJetOpenTempTable3 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOpenTempTable3 = ( PFN_JetOpenTempTable3 ) ( GetProcAddress( hEseDll, "JetOpenTempTable3" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOpenTempTable3 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOpenTempTable3", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOpenTempTable3)( sesid, prgcolumndef, ccolumn, pidxunicode, grbit, ptableid, prgcolumnid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOpenTemporaryTable(
    JET_SESID               sesid,
    JET_OPENTEMPORARYTABLE  *popentemporarytable
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOpenTemporaryTable ) ( 
    JET_SESID               sesid,
    JET_OPENTEMPORARYTABLE  *popentemporarytable  );

    static PFN_JetOpenTemporaryTable pfnJetOpenTemporaryTable = NULL;

    if ( NULL == pfnJetOpenTemporaryTable )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOpenTemporaryTable = ( PFN_JetOpenTemporaryTable ) ( GetProcAddress( hEseDll, "JetOpenTemporaryTable" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOpenTemporaryTable )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOpenTemporaryTable", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOpenTemporaryTable)( sesid, popentemporarytable );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetIndexRange(
    JET_SESID sesid,
    JET_TABLEID tableidSrc,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetIndexRange ) ( JET_SESID sesid,
    JET_TABLEID tableidSrc, JET_GRBIT grbit );

    static PFN_JetSetIndexRange pfnJetSetIndexRange = NULL;

    if ( NULL == pfnJetSetIndexRange )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetIndexRange = ( PFN_JetSetIndexRange ) ( GetProcAddress( hEseDll, "JetSetIndexRange" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetIndexRange )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetIndexRange", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetIndexRange)( sesid, tableidSrc, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetIndexRecordCount(
    JET_SESID sesid,
    JET_TABLEID tableid,
    unsigned long *pcrec,
    unsigned long crecMax
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetIndexRecordCount ) ( JET_SESID sesid,
    JET_TABLEID tableid, unsigned long *pcrec, unsigned long crecMax  );

    static PFN_JetIndexRecordCount pfnJetIndexRecordCount = NULL;

    if ( NULL == pfnJetIndexRecordCount )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetIndexRecordCount = ( PFN_JetIndexRecordCount ) ( GetProcAddress( hEseDll, "JetIndexRecordCount" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetIndexRecordCount )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetIndexRecordCount", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetIndexRecordCount)( sesid, tableid, pcrec, crecMax );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRetrieveKey(
    JET_SESID sesid,
    JET_TABLEID tableid,
    __out_bcount_part(cbMax,
    *pcbActual) void *pvData,
    unsigned long cbMax,
    unsigned long *pcbActual,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRetrieveKey ) ( 
    JET_SESID sesid,
    JET_TABLEID tableid,
    __out_bcount_part(cbMax, *pcbActual) void *pvData,
    unsigned long cbMax,
    unsigned long *pcbActual,
    JET_GRBIT grbit  );

    static PFN_JetRetrieveKey pfnJetRetrieveKey = NULL;

    if ( NULL == pfnJetRetrieveKey )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRetrieveKey = ( PFN_JetRetrieveKey ) ( GetProcAddress( hEseDll, "JetRetrieveKey" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRetrieveKey )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRetrieveKey", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRetrieveKey)( sesid, tableid, pvData, cbMax, pcbActual, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetBeginExternalBackup(
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetBeginExternalBackup ) (  JET_GRBIT grbit  );

    static PFN_JetBeginExternalBackup pfnJetBeginExternalBackup = NULL;

    if ( NULL == pfnJetBeginExternalBackup )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetBeginExternalBackup = ( PFN_JetBeginExternalBackup ) ( GetProcAddress( hEseDll, "JetBeginExternalBackup" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetBeginExternalBackup )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetBeginExternalBackup", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetBeginExternalBackup)( grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetBeginExternalBackupInstance(
    JET_INSTANCE instance,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetBeginExternalBackupInstance ) (  JET_INSTANCE instance, JET_GRBIT grbit  );

    static PFN_JetBeginExternalBackupInstance pfnJetBeginExternalBackupInstance = NULL;

    if ( NULL == pfnJetBeginExternalBackupInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetBeginExternalBackupInstance = ( PFN_JetBeginExternalBackupInstance ) ( GetProcAddress( hEseDll, "JetBeginExternalBackupInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetBeginExternalBackupInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetBeginExternalBackupInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetBeginExternalBackupInstance)( instance, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetAttachInfo(
    __out_bcount_part_opt(cbMax,
    *pcbActual) void *pv,
    unsigned long cbMax,
    unsigned long *pcbActual
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetAttachInfo ) ( 
    __out_bcount_part_opt(cbMax, *pcbActual) void *pv,
    unsigned long cbMax,
    unsigned long *pcbActual  );

    static PFN_JetGetAttachInfo pfnJetGetAttachInfo = NULL;

    if ( NULL == pfnJetGetAttachInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetAttachInfo = ( PFN_JetGetAttachInfo ) ( GetProcAddress( hEseDll, "JetGetAttachInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetAttachInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetAttachInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetAttachInfo)( pv, cbMax, pcbActual );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetAttachInfoInstance(
    JET_INSTANCE    instance,
    __out_bcount_part_opt(cbMax,
    *pcbActual) void            *pv,
    unsigned long   cbMax,
    unsigned long   *pcbActual
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetAttachInfoInstance ) (   JET_INSTANCE    instance,
    __out_bcount_part_opt(cbMax, *pcbActual) void           *pv,
    unsigned long   cbMax,
    unsigned long   *pcbActual  );

    static PFN_JetGetAttachInfoInstance pfnJetGetAttachInfoInstance = NULL;

    if ( NULL == pfnJetGetAttachInfoInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetAttachInfoInstance = ( PFN_JetGetAttachInfoInstance ) ( GetProcAddress( hEseDll, "JetGetAttachInfoInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetAttachInfoInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetAttachInfoInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetAttachInfoInstance)( instance, pv, cbMax, pcbActual );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetReadFile(
    JET_HANDLE hfFile,
    __out_bcount_part(cb,
    *pcbActual ) void *pv,
    unsigned long cb,
    unsigned long *pcbActual
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetReadFile ) (  JET_HANDLE hfFile,
    __out_bcount_part(cb, *pcbActual ) void *pv,
    unsigned long cb,
    unsigned long *pcbActual  );

    static PFN_JetReadFile pfnJetReadFile = NULL;

    if ( NULL == pfnJetReadFile )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetReadFile = ( PFN_JetReadFile ) ( GetProcAddress( hEseDll, "JetReadFile" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetReadFile )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetReadFile", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetReadFile)( hfFile, pv, cb, pcbActual );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetReadFileInstance(
    JET_INSTANCE instance,
    JET_HANDLE hfFile,
    __out_bcount_part(cb,
    *pcb) void *pv,
    unsigned long cb,
    unsigned long *pcb
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetReadFileInstance ) (    JET_INSTANCE instance,
                                        JET_HANDLE hfFile,
    __out_bcount_part(cb, *pcb) void *pv,
                                        unsigned long cb,
                                        unsigned long *pcb  );

    static PFN_JetReadFileInstance pfnJetReadFileInstance = NULL;

    if ( NULL == pfnJetReadFileInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetReadFileInstance = ( PFN_JetReadFileInstance ) ( GetProcAddress( hEseDll, "JetReadFileInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetReadFileInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetReadFileInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetReadFileInstance)( instance, hfFile, pv, cb, pcb );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCloseFile(
    JET_HANDLE hfFile
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCloseFile ) (  JET_HANDLE hfFile  );

    static PFN_JetCloseFile pfnJetCloseFile = NULL;

    if ( NULL == pfnJetCloseFile )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCloseFile = ( PFN_JetCloseFile ) ( GetProcAddress( hEseDll, "JetCloseFile" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCloseFile )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCloseFile", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCloseFile)( hfFile );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCloseFileInstance(
    JET_INSTANCE instance,
    JET_HANDLE hfFile
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCloseFileInstance ) (  JET_INSTANCE instance, JET_HANDLE hfFile  );

    static PFN_JetCloseFileInstance pfnJetCloseFileInstance = NULL;

    if ( NULL == pfnJetCloseFileInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCloseFileInstance = ( PFN_JetCloseFileInstance ) ( GetProcAddress( hEseDll, "JetCloseFileInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCloseFileInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCloseFileInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCloseFileInstance)( instance, hfFile );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetLogInfo(
    __out_bcount_part_opt(cbMax,
    *pcbActual) void *pv,
    unsigned long cbMax,
    unsigned long *pcbActual
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetLogInfo ) ( 
    __out_bcount_part_opt(cbMax, *pcbActual) void *pv,
    unsigned long cbMax,
    unsigned long *pcbActual  );

    static PFN_JetGetLogInfo pfnJetGetLogInfo = NULL;

    if ( NULL == pfnJetGetLogInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetLogInfo = ( PFN_JetGetLogInfo ) ( GetProcAddress( hEseDll, "JetGetLogInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetLogInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetLogInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetLogInfo)( pv, cbMax, pcbActual );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetLogInfoInstance(
    JET_INSTANCE instance,
    __out_bcount_part_opt(cbMax,
    *pcbActual) void *pv,
    unsigned long cbMax,
    unsigned long *pcbActual
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetLogInfoInstance ) (  JET_INSTANCE instance,
                                        __out_bcount_part_opt(cbMax, *pcbActual) void *pv,
                                        unsigned long cbMax,
                                        unsigned long *pcbActual  );

    static PFN_JetGetLogInfoInstance pfnJetGetLogInfoInstance = NULL;

    if ( NULL == pfnJetGetLogInfoInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetLogInfoInstance = ( PFN_JetGetLogInfoInstance ) ( GetProcAddress( hEseDll, "JetGetLogInfoInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetLogInfoInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetLogInfoInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetLogInfoInstance)( instance, pv, cbMax, pcbActual );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetLogInfoInstance2(
    JET_INSTANCE instance,
    __out_bcount_part_opt(cbMax,
    *pcbActual) void *pv,
    unsigned long cbMax,
    unsigned long *pcbActual,
    JET_LOGINFO * pLogInfo
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetLogInfoInstance2 ) (  JET_INSTANCE instance,
                                        __out_bcount_part_opt(cbMax, *pcbActual) void *pv,
                                        unsigned long cbMax,
                                        unsigned long *pcbActual,
                                        JET_LOGINFO * pLogInfo );

    static PFN_JetGetLogInfoInstance2 pfnJetGetLogInfoInstance2 = NULL;

    if ( NULL == pfnJetGetLogInfoInstance2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetLogInfoInstance2 = ( PFN_JetGetLogInfoInstance2 ) ( GetProcAddress( hEseDll, "JetGetLogInfoInstance2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetLogInfoInstance2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetLogInfoInstance2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetLogInfoInstance2)( instance, pv, cbMax, pcbActual, pLogInfo );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetTruncateLogInfoInstance(
    JET_INSTANCE instance,
    __out_bcount_part_opt(cbMax,
    *pcbActual) void *pv,
    unsigned long cbMax,
    unsigned long *pcbActual
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetTruncateLogInfoInstance ) (  JET_INSTANCE instance,
                                                __out_bcount_part_opt(cbMax, *pcbActual) void *pv,
                                                unsigned long cbMax,
                                                unsigned long *pcbActual  );

    static PFN_JetGetTruncateLogInfoInstance pfnJetGetTruncateLogInfoInstance = NULL;

    if ( NULL == pfnJetGetTruncateLogInfoInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetTruncateLogInfoInstance = ( PFN_JetGetTruncateLogInfoInstance ) ( GetProcAddress( hEseDll, "JetGetTruncateLogInfoInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetTruncateLogInfoInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetTruncateLogInfoInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetTruncateLogInfoInstance)( instance, pv, cbMax, pcbActual );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetTruncateLog(
    void
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetTruncateLog ) (  void  );

    static PFN_JetTruncateLog pfnJetTruncateLog = NULL;

    if ( NULL == pfnJetTruncateLog )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetTruncateLog = ( PFN_JetTruncateLog ) ( GetProcAddress( hEseDll, "JetTruncateLog" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetTruncateLog )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetTruncateLog", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetTruncateLog)(  );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetTruncateLogInstance(
    JET_INSTANCE instance
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetTruncateLogInstance ) (  JET_INSTANCE instance  );

    static PFN_JetTruncateLogInstance pfnJetTruncateLogInstance = NULL;

    if ( NULL == pfnJetTruncateLogInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetTruncateLogInstance = ( PFN_JetTruncateLogInstance ) ( GetProcAddress( hEseDll, "JetTruncateLogInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetTruncateLogInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetTruncateLogInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetTruncateLogInstance)( instance );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetEndExternalBackup(
    void
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetEndExternalBackup ) (  void  );

    static PFN_JetEndExternalBackup pfnJetEndExternalBackup = NULL;

    if ( NULL == pfnJetEndExternalBackup )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetEndExternalBackup = ( PFN_JetEndExternalBackup ) ( GetProcAddress( hEseDll, "JetEndExternalBackup" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetEndExternalBackup )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetEndExternalBackup", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetEndExternalBackup)(  );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetEndExternalBackupInstance(
    JET_INSTANCE instance
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetEndExternalBackupInstance ) (  JET_INSTANCE instance  );

    static PFN_JetEndExternalBackupInstance pfnJetEndExternalBackupInstance = NULL;

    if ( NULL == pfnJetEndExternalBackupInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetEndExternalBackupInstance = ( PFN_JetEndExternalBackupInstance ) ( GetProcAddress( hEseDll, "JetEndExternalBackupInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetEndExternalBackupInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetEndExternalBackupInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetEndExternalBackupInstance)( instance );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetEndExternalBackupInstance2(
    JET_INSTANCE instance,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetEndExternalBackupInstance2 ) (  JET_INSTANCE instance, JET_GRBIT grbit  );

    static PFN_JetEndExternalBackupInstance2 pfnJetEndExternalBackupInstance2 = NULL;

    if ( NULL == pfnJetEndExternalBackupInstance2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetEndExternalBackupInstance2 = ( PFN_JetEndExternalBackupInstance2 ) ( GetProcAddress( hEseDll, "JetEndExternalBackupInstance2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetEndExternalBackupInstance2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetEndExternalBackupInstance2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetEndExternalBackupInstance2)( instance, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRegisterCallback(
    JET_SESID               sesid,
    JET_TABLEID             tableid,
    JET_CBTYP               cbtyp,
    JET_CALLBACK            pCallback,
    void *                  pvContext,
    JET_HANDLE              *phCallbackId
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRegisterCallback ) ( 
    JET_SESID               sesid,
    JET_TABLEID             tableid,
    JET_CBTYP               cbtyp,
    JET_CALLBACK            pCallback,
    void *                  pvContext,
    JET_HANDLE              *phCallbackId  );

    static PFN_JetRegisterCallback pfnJetRegisterCallback = NULL;

    if ( NULL == pfnJetRegisterCallback )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRegisterCallback = ( PFN_JetRegisterCallback ) ( GetProcAddress( hEseDll, "JetRegisterCallback" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRegisterCallback )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRegisterCallback", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRegisterCallback)( sesid, tableid, cbtyp, pCallback, pvContext, phCallbackId );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetUnregisterCallback(
    JET_SESID               sesid,
    JET_TABLEID             tableid,
    JET_CBTYP               cbtyp,
    JET_HANDLE              hCallbackId
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetUnregisterCallback ) ( 
    JET_SESID               sesid,
    JET_TABLEID             tableid,
    JET_CBTYP               cbtyp,
    JET_HANDLE              hCallbackId  );

    static PFN_JetUnregisterCallback pfnJetUnregisterCallback = NULL;

    if ( NULL == pfnJetUnregisterCallback )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetUnregisterCallback = ( PFN_JetUnregisterCallback ) ( GetProcAddress( hEseDll, "JetUnregisterCallback" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetUnregisterCallback )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetUnregisterCallback", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetUnregisterCallback)( sesid, tableid, cbtyp, hCallbackId );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetInstanceInfo(
    unsigned long *pcInstanceInfo,
    JET_INSTANCE_INFO ** paInstanceInfo
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetInstanceInfo ) (  unsigned long *pcInstanceInfo, JET_INSTANCE_INFO ** paInstanceInfo  );

    static PFN_JetGetInstanceInfo pfnJetGetInstanceInfo = NULL;

    if ( NULL == pfnJetGetInstanceInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetInstanceInfo = ( PFN_JetGetInstanceInfo ) ( GetProcAddress( hEseDll, "JetGetInstanceInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetInstanceInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetInstanceInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetInstanceInfo)( pcInstanceInfo, paInstanceInfo );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetFreeBuffer(
    __notnull char * pbBuf
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetFreeBuffer ) (  __notnull char * pbBuf  );

    static PFN_JetFreeBuffer pfnJetFreeBuffer = NULL;

    if ( NULL == pfnJetFreeBuffer )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetFreeBuffer = ( PFN_JetFreeBuffer ) ( GetProcAddress( hEseDll, "JetFreeBuffer" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetFreeBuffer )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetFreeBuffer", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetFreeBuffer)( pbBuf );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetLS(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_LS          ls,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetLS ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_LS          ls,
    JET_GRBIT       grbit  );

    static PFN_JetSetLS pfnJetSetLS = NULL;

    if ( NULL == pfnJetSetLS )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetLS = ( PFN_JetSetLS ) ( GetProcAddress( hEseDll, "JetSetLS" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetLS )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetLS", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetLS)( sesid, tableid, ls, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetLS(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_LS          *pls,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetLS ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    JET_LS          *pls,
    JET_GRBIT       grbit  );

    static PFN_JetGetLS pfnJetGetLS = NULL;

    if ( NULL == pfnJetGetLS )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetLS = ( PFN_JetGetLS ) ( GetProcAddress( hEseDll, "JetGetLS" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetLS )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetLS", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetLS)( sesid, tableid, pls, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetTracing(
    const JET_TRACEOP   traceop,
    const JET_TRACETAG  tracetag,
    const JET_API_PTR   ul
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetTracing ) ( 
    const JET_TRACEOP   traceop,
    const JET_TRACETAG  tracetag,
    const JET_API_PTR   ul  );

    static PFN_JetTracing pfnJetTracing = NULL;

    if ( NULL == pfnJetTracing )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetTracing = ( PFN_JetTracing ) ( GetProcAddress( hEseDll, "JetTracing" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetTracing )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetTracing", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetTracing)( traceop, tracetag, ul );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOSSnapshotPrepare(
    JET_OSSNAPID * psnapId,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOSSnapshotPrepare ) (  JET_OSSNAPID * psnapId, const JET_GRBIT grbit  );

    static PFN_JetOSSnapshotPrepare pfnJetOSSnapshotPrepare = NULL;

    if ( NULL == pfnJetOSSnapshotPrepare )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOSSnapshotPrepare = ( PFN_JetOSSnapshotPrepare ) ( GetProcAddress( hEseDll, "JetOSSnapshotPrepare" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOSSnapshotPrepare )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOSSnapshotPrepare", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOSSnapshotPrepare)( psnapId, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOSSnapshotPrepareInstance(
    JET_OSSNAPID snapId,
    JET_INSTANCE    instance,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOSSnapshotPrepareInstance ) (  JET_OSSNAPID snapId, JET_INSTANCE    instance, const JET_GRBIT grbit  );

    static PFN_JetOSSnapshotPrepareInstance pfnJetOSSnapshotPrepareInstance = NULL;

    if ( NULL == pfnJetOSSnapshotPrepareInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOSSnapshotPrepareInstance = ( PFN_JetOSSnapshotPrepareInstance ) ( GetProcAddress( hEseDll, "JetOSSnapshotPrepareInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOSSnapshotPrepareInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOSSnapshotPrepareInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOSSnapshotPrepareInstance)( snapId, instance, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOSSnapshotFreeze(
    const JET_OSSNAPID snapId,
    unsigned long *pcInstanceInfo,
    JET_INSTANCE_INFO ** paInstanceInfo,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOSSnapshotFreeze ) (  const JET_OSSNAPID snapId, unsigned long *pcInstanceInfo, JET_INSTANCE_INFO ** paInstanceInfo, const JET_GRBIT grbit  );

    static PFN_JetOSSnapshotFreeze pfnJetOSSnapshotFreeze = NULL;

    if ( NULL == pfnJetOSSnapshotFreeze )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOSSnapshotFreeze = ( PFN_JetOSSnapshotFreeze ) ( GetProcAddress( hEseDll, "JetOSSnapshotFreeze" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOSSnapshotFreeze )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOSSnapshotFreeze", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOSSnapshotFreeze)( snapId, pcInstanceInfo, paInstanceInfo, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOSSnapshotThaw(
    const JET_OSSNAPID snapId,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOSSnapshotThaw ) (  const JET_OSSNAPID snapId, const JET_GRBIT grbit  );

    static PFN_JetOSSnapshotThaw pfnJetOSSnapshotThaw = NULL;

    if ( NULL == pfnJetOSSnapshotThaw )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOSSnapshotThaw = ( PFN_JetOSSnapshotThaw ) ( GetProcAddress( hEseDll, "JetOSSnapshotThaw" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOSSnapshotThaw )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOSSnapshotThaw", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOSSnapshotThaw)( snapId, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOSSnapshotAbort(
    const JET_OSSNAPID snapId,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOSSnapshotAbort ) (  const JET_OSSNAPID snapId, const JET_GRBIT grbit  );

    static PFN_JetOSSnapshotAbort pfnJetOSSnapshotAbort = NULL;

    if ( NULL == pfnJetOSSnapshotAbort )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOSSnapshotAbort = ( PFN_JetOSSnapshotAbort ) ( GetProcAddress( hEseDll, "JetOSSnapshotAbort" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOSSnapshotAbort )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOSSnapshotAbort", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOSSnapshotAbort)( snapId, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOSSnapshotTruncateLog(
    const JET_OSSNAPID snapId,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOSSnapshotTruncateLog ) (  const JET_OSSNAPID snapId, const JET_GRBIT grbit  );

    static PFN_JetOSSnapshotTruncateLog pfnJetOSSnapshotTruncateLog = NULL;

    if ( NULL == pfnJetOSSnapshotTruncateLog )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOSSnapshotTruncateLog = ( PFN_JetOSSnapshotTruncateLog ) ( GetProcAddress( hEseDll, "JetOSSnapshotTruncateLog" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOSSnapshotTruncateLog )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOSSnapshotTruncateLog", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOSSnapshotTruncateLog)( snapId, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOSSnapshotTruncateLogInstance(
    const JET_OSSNAPID snapId,
    JET_INSTANCE    instance,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOSSnapshotTruncateLogInstance ) (  const JET_OSSNAPID snapId, JET_INSTANCE  instance, const JET_GRBIT grbit  );

    static PFN_JetOSSnapshotTruncateLogInstance pfnJetOSSnapshotTruncateLogInstance = NULL;

    if ( NULL == pfnJetOSSnapshotTruncateLogInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOSSnapshotTruncateLogInstance = ( PFN_JetOSSnapshotTruncateLogInstance ) ( GetProcAddress( hEseDll, "JetOSSnapshotTruncateLogInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOSSnapshotTruncateLogInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOSSnapshotTruncateLogInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOSSnapshotTruncateLogInstance)( snapId, instance, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOSSnapshotGetFreezeInfo(
    const JET_OSSNAPID snapId,
    unsigned long *pcInstanceInfo,
    JET_INSTANCE_INFO ** paInstanceInfo,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOSSnapshotGetFreezeInfo ) (  const JET_OSSNAPID snapId, unsigned long *pcInstanceInfo, JET_INSTANCE_INFO ** paInstanceInfo, const JET_GRBIT grbit  );

    static PFN_JetOSSnapshotGetFreezeInfo pfnJetOSSnapshotGetFreezeInfo = NULL;

    if ( NULL == pfnJetOSSnapshotGetFreezeInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOSSnapshotGetFreezeInfo = ( PFN_JetOSSnapshotGetFreezeInfo ) ( GetProcAddress( hEseDll, "JetOSSnapshotGetFreezeInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOSSnapshotGetFreezeInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOSSnapshotGetFreezeInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOSSnapshotGetFreezeInfo)( snapId, pcInstanceInfo, paInstanceInfo, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOSSnapshotEnd(
    const JET_OSSNAPID snapId,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOSSnapshotEnd ) (  const JET_OSSNAPID snapId, const JET_GRBIT grbit  );

    static PFN_JetOSSnapshotEnd pfnJetOSSnapshotEnd = NULL;

    if ( NULL == pfnJetOSSnapshotEnd )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOSSnapshotEnd = ( PFN_JetOSSnapshotEnd ) ( GetProcAddress( hEseDll, "JetOSSnapshotEnd" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOSSnapshotEnd )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOSSnapshotEnd", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOSSnapshotEnd)( snapId, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetBeginSurrogateBackup(
    JET_INSTANCE    instance,
    unsigned long       lgenFirst,
    unsigned long       lgenLast,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetBeginSurrogateBackup ) ( 
    JET_INSTANCE    instance,
    unsigned long       lgenFirst,
    unsigned long       lgenLast,
    JET_GRBIT       grbit  );

    static PFN_JetBeginSurrogateBackup pfnJetBeginSurrogateBackup = NULL;

    if ( NULL == pfnJetBeginSurrogateBackup )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetBeginSurrogateBackup = ( PFN_JetBeginSurrogateBackup ) ( GetProcAddress( hEseDll, "JetBeginSurrogateBackup" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetBeginSurrogateBackup )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetBeginSurrogateBackup", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetBeginSurrogateBackup)( instance, lgenFirst, lgenLast, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetEndSurrogateBackup(
    JET_INSTANCE    instance,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetEndSurrogateBackup ) ( 
    JET_INSTANCE    instance,
    JET_GRBIT       grbit  );

    static PFN_JetEndSurrogateBackup pfnJetEndSurrogateBackup = NULL;

    if ( NULL == pfnJetEndSurrogateBackup )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetEndSurrogateBackup = ( PFN_JetEndSurrogateBackup ) ( GetProcAddress( hEseDll, "JetEndSurrogateBackup" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetEndSurrogateBackup )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetEndSurrogateBackup", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetEndSurrogateBackup)( instance, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetPrereadKeys(
    __in JET_SESID                              sesid,
    __in JET_TABLEID                                tableid,
    __in_ecount(ckeys) const void **                rgpvKeys,
    __in_ecount(ckeys) const unsigned long *            rgcbKeys,
    __in long                                       ckeys,
    __out_opt long *                                pckeysPreread,
    __in JET_GRBIT                              grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetPrereadKeys ) ( 
    __in JET_SESID                              sesid,
    __in JET_TABLEID                                tableid,
    __in_ecount(ckeys) const void **                rgpvKeys,
    __in_ecount(ckeys) const unsigned long *            rgcbKeys,
    __in long                                       ckeys,
    __out_opt long *                                pckeysPreread,
    __in JET_GRBIT                              grbit  );

    static PFN_JetPrereadKeys pfnJetPrereadKeys = NULL;

    if ( NULL == pfnJetPrereadKeys )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetPrereadKeys = ( PFN_JetPrereadKeys ) ( GetProcAddress( hEseDll, "JetPrereadKeys" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetPrereadKeys )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetPrereadKeys", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetPrereadKeys)( sesid, tableid, rgpvKeys, rgcbKeys, ckeys, pckeysPreread, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetConsumeLogData(
    __in    JET_INSTANCE        instance,
    __in    JET_EMITDATACTX *   pEmitLogDataCtx,
    __in    void *              pvLogData,
    __in    unsigned long       cbLogData,
    __in    JET_GRBIT           grbits
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetConsumeLogData ) ( 
    __in    JET_INSTANCE        instance,
    __in    JET_EMITDATACTX *   pEmitLogDataCtx,
    __in    void *              pvLogData,
    __in    unsigned long       cbLogData,
    __in    JET_GRBIT           grbits  );

    static PFN_JetConsumeLogData pfnJetConsumeLogData = NULL;

    if ( NULL == pfnJetConsumeLogData )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetConsumeLogData = ( PFN_JetConsumeLogData ) ( GetProcAddress( hEseDll, "JetConsumeLogData" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetConsumeLogData )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetConsumeLogData", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetConsumeLogData)( instance, pEmitLogDataCtx, pvLogData, cbLogData, grbits );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetTestHook(
    __in        const TESTHOOK_OP   opcode,
    __inout_opt void * const        pv
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetTestHook ) ( 
    __in        const TESTHOOK_OP   opcode,
    __inout_opt void * const        pv  );

    static PFN_JetTestHook pfnJetTestHook = NULL;

    if ( NULL == pfnJetTestHook )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetTestHook = ( PFN_JetTestHook ) ( GetProcAddress( hEseDll, "JetTestHook" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetTestHook )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetTestHook", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetTestHook)( opcode, pv );
    goto Cleanup;
Cleanup:

    return err;
}


