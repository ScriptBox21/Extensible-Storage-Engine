// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#include "ese_common.hxx"
#include "esetest_bounce.hxx"
#include <stdlib.h>
#include <strsafe.h>
#include <windows.h>

JET_ERR
BounceJetCreateInstance(
    JET_INSTANCE *pinstance,
    const char * szInstanceName
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCreateInstance ) (  JET_INSTANCE *pinstance, const char * szInstanceName  );

    static PFN_JetCreateInstance pfnJetCreateInstance = NULL;

    if ( NULL == pfnJetCreateInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCreateInstance = ( PFN_JetCreateInstance ) ( GetProcAddress( hEseDll, "JetCreateInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCreateInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCreateInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCreateInstance)( pinstance, szInstanceName );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCreateInstance2(
    JET_INSTANCE *pinstance,
    const char * szInstanceName,
    const char * szDisplayName,
    JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCreateInstance2 ) ( 
    JET_INSTANCE *pinstance,
    const char * szInstanceName,
    const char * szDisplayName,
    JET_GRBIT grbit  );

    static PFN_JetCreateInstance2 pfnJetCreateInstance2 = NULL;

    if ( NULL == pfnJetCreateInstance2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCreateInstance2 = ( PFN_JetCreateInstance2 ) ( GetProcAddress( hEseDll, "JetCreateInstance2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCreateInstance2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCreateInstance2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCreateInstance2)( pinstance, szInstanceName, szDisplayName, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetSystemParameter(
    JET_INSTANCE    *pinstance,
    JET_SESID       sesid,
    unsigned long   paramid,
    __in_opt JET_API_PTR        lParam,
    __in_opt JET_PCSTR      szParam
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetSystemParameter ) ( 
    JET_INSTANCE    *pinstance,
    JET_SESID       sesid,
    unsigned long   paramid,
    __in_opt JET_API_PTR        lParam,
    __in_opt JET_PCSTR      szParam  );

    static PFN_JetSetSystemParameter pfnJetSetSystemParameter = NULL;

    if ( NULL == pfnJetSetSystemParameter )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetSystemParameter = ( PFN_JetSetSystemParameter ) ( GetProcAddress( hEseDll, "JetSetSystemParameter" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetSystemParameter )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetSystemParameter", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetSystemParameter)( pinstance, sesid, paramid, lParam, szParam );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetBeginSession(
    JET_INSTANCE    instance,
    JET_SESID       *psesid,
    __in_opt JET_PCSTR  szUserName,
    __in_opt JET_PCSTR  szPassword
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetBeginSession ) ( 
    JET_INSTANCE    instance,
    JET_SESID       *psesid,
    __in_opt JET_PCSTR  szUserName,
    __in_opt JET_PCSTR  szPassword  );

    static PFN_JetBeginSession pfnJetBeginSession = NULL;

    if ( NULL == pfnJetBeginSession )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetBeginSession = ( PFN_JetBeginSession ) ( GetProcAddress( hEseDll, "JetBeginSession" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetBeginSession )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetBeginSession", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetBeginSession)( instance, psesid, szUserName, szPassword );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCreateDatabase(
    JET_SESID       sesid,
    const char      *szFilename,
    const char      *szConnect,
    JET_DBID        *pdbid,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCreateDatabase ) ( 
    JET_SESID       sesid,
    const char      *szFilename,
    const char      *szConnect,
    JET_DBID        *pdbid,
    JET_GRBIT       grbit  );

    static PFN_JetCreateDatabase pfnJetCreateDatabase = NULL;

    if ( NULL == pfnJetCreateDatabase )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCreateDatabase = ( PFN_JetCreateDatabase ) ( GetProcAddress( hEseDll, "JetCreateDatabase" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCreateDatabase )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCreateDatabase", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCreateDatabase)( sesid, szFilename, szConnect, pdbid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCreateDatabase2(
    JET_SESID       sesid,
    const char      *szFilename,
    const unsigned long cpgDatabaseSizeMax,
    JET_DBID        *pdbid,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCreateDatabase2 ) ( 
    JET_SESID       sesid,
    const char      *szFilename,
    const unsigned long cpgDatabaseSizeMax,
    JET_DBID        *pdbid,
    JET_GRBIT       grbit  );

    static PFN_JetCreateDatabase2 pfnJetCreateDatabase2 = NULL;

    if ( NULL == pfnJetCreateDatabase2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCreateDatabase2 = ( PFN_JetCreateDatabase2 ) ( GetProcAddress( hEseDll, "JetCreateDatabase2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCreateDatabase2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCreateDatabase2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCreateDatabase2)( sesid, szFilename, cpgDatabaseSizeMax, pdbid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCreateDatabaseWithStreaming(
    JET_SESID       sesid,
    const char      *szDbFileName,
    const char      *szSLVFileName,
    const char      *szSLVRootName,
    const unsigned long cpgDatabaseSizeMax,
    JET_DBID        *pdbid,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCreateDatabaseWithStreaming ) ( 
    JET_SESID       sesid,
    const char      *szDbFileName,
    const char      *szSLVFileName,
    const char      *szSLVRootName,
    const unsigned long cpgDatabaseSizeMax,
    JET_DBID        *pdbid,
    JET_GRBIT       grbit  );

    static PFN_JetCreateDatabaseWithStreaming pfnJetCreateDatabaseWithStreaming = NULL;

    if ( NULL == pfnJetCreateDatabaseWithStreaming )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCreateDatabaseWithStreaming = ( PFN_JetCreateDatabaseWithStreaming ) ( GetProcAddress( hEseDll, "JetCreateDatabaseWithStreaming" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCreateDatabaseWithStreaming )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCreateDatabaseWithStreaming", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCreateDatabaseWithStreaming)( sesid, szDbFileName, szSLVFileName, szSLVRootName, cpgDatabaseSizeMax, pdbid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetAttachDatabase(
    JET_SESID       sesid,
    const char      *szFilename,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetAttachDatabase ) ( 
    JET_SESID       sesid,
    const char      *szFilename,
    JET_GRBIT       grbit  );

    static PFN_JetAttachDatabase pfnJetAttachDatabase = NULL;

    if ( NULL == pfnJetAttachDatabase )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetAttachDatabase = ( PFN_JetAttachDatabase ) ( GetProcAddress( hEseDll, "JetAttachDatabase" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetAttachDatabase )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetAttachDatabase", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetAttachDatabase)( sesid, szFilename, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetAttachDatabase2(
    JET_SESID       sesid,
    const char      *szFilename,
    const unsigned long cpgDatabaseSizeMax,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetAttachDatabase2 ) ( 
    JET_SESID       sesid,
    const char      *szFilename,
    const unsigned long cpgDatabaseSizeMax,
    JET_GRBIT       grbit  );

    static PFN_JetAttachDatabase2 pfnJetAttachDatabase2 = NULL;

    if ( NULL == pfnJetAttachDatabase2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetAttachDatabase2 = ( PFN_JetAttachDatabase2 ) ( GetProcAddress( hEseDll, "JetAttachDatabase2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetAttachDatabase2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetAttachDatabase2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetAttachDatabase2)( sesid, szFilename, cpgDatabaseSizeMax, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetAttachDatabase3(
    JET_SESID       sesid,
    const char      *szFilename,
    const JET_SETDBPARAM* const rgsetdbparam,
    const unsigned long csetdbparam,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetAttachDatabase3 ) ( 
    JET_SESID       sesid,
    const char      *szFilename,
    const JET_SETDBPARAM* const rgsetdbparam,
    const unsigned long csetdbparam,
    JET_GRBIT       grbit  );

    static PFN_JetAttachDatabase3 pfnJetAttachDatabase3 = NULL;

    if ( NULL == pfnJetAttachDatabase3 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetAttachDatabase3 = ( PFN_JetAttachDatabase3 ) ( GetProcAddress( hEseDll, "JetAttachDatabase3" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetAttachDatabase3 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetAttachDatabase3", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetAttachDatabase3)( sesid, szFilename, rgsetdbparam, csetdbparam, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetAttachDatabaseWithStreaming(
    JET_SESID       sesid,
    const char      *szDbFileName,
    const char      *szSLVFileName,
    const char      *szSLVRootName,
    const unsigned long cpgDatabaseSizeMax,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetAttachDatabaseWithStreaming ) ( 
    JET_SESID       sesid,
    const char      *szDbFileName,
    const char      *szSLVFileName,
    const char      *szSLVRootName,
    const unsigned long cpgDatabaseSizeMax,
    JET_GRBIT       grbit  );

    static PFN_JetAttachDatabaseWithStreaming pfnJetAttachDatabaseWithStreaming = NULL;

    if ( NULL == pfnJetAttachDatabaseWithStreaming )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetAttachDatabaseWithStreaming = ( PFN_JetAttachDatabaseWithStreaming ) ( GetProcAddress( hEseDll, "JetAttachDatabaseWithStreaming" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetAttachDatabaseWithStreaming )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetAttachDatabaseWithStreaming", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetAttachDatabaseWithStreaming)( sesid, szDbFileName, szSLVFileName, szSLVRootName, cpgDatabaseSizeMax, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDetachDatabase(
    JET_SESID       sesid,
    const char      *szFilename
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDetachDatabase ) ( 
    JET_SESID       sesid,
    const char      *szFilename  );

    static PFN_JetDetachDatabase pfnJetDetachDatabase = NULL;

    if ( NULL == pfnJetDetachDatabase )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDetachDatabase = ( PFN_JetDetachDatabase ) ( GetProcAddress( hEseDll, "JetDetachDatabase" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDetachDatabase )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDetachDatabase", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDetachDatabase)( sesid, szFilename );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDetachDatabase2(
    JET_SESID       sesid,
    const char      *szFilename,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDetachDatabase2 ) ( 
    JET_SESID       sesid,
    const char      *szFilename,
    JET_GRBIT       grbit );

    static PFN_JetDetachDatabase2 pfnJetDetachDatabase2 = NULL;

    if ( NULL == pfnJetDetachDatabase2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDetachDatabase2 = ( PFN_JetDetachDatabase2 ) ( GetProcAddress( hEseDll, "JetDetachDatabase2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDetachDatabase2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDetachDatabase2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDetachDatabase2)( sesid, szFilename, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCreateTable(
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    unsigned long   lPages,
    unsigned long   lDensity,
    JET_TABLEID     *ptableid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCreateTable ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    unsigned long   lPages,
    unsigned long   lDensity,
    JET_TABLEID     *ptableid  );

    static PFN_JetCreateTable pfnJetCreateTable = NULL;

    if ( NULL == pfnJetCreateTable )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCreateTable = ( PFN_JetCreateTable ) ( GetProcAddress( hEseDll, "JetCreateTable" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCreateTable )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCreateTable", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCreateTable)( sesid, dbid, szTableName, lPages, lDensity, ptableid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDeleteTable(
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDeleteTable ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName  );

    static PFN_JetDeleteTable pfnJetDeleteTable = NULL;

    if ( NULL == pfnJetDeleteTable )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDeleteTable = ( PFN_JetDeleteTable ) ( GetProcAddress( hEseDll, "JetDeleteTable" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDeleteTable )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDeleteTable", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDeleteTable)( sesid, dbid, szTableName );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRenameTable(
    JET_SESID sesid,
    JET_DBID dbid,
    const char *szName,
    const char *szNameNew
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRenameTable ) ( 
    JET_SESID sesid,
    JET_DBID dbid,
    const char *szName,
    const char *szNameNew  );

    static PFN_JetRenameTable pfnJetRenameTable = NULL;

    if ( NULL == pfnJetRenameTable )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRenameTable = ( PFN_JetRenameTable ) ( GetProcAddress( hEseDll, "JetRenameTable" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRenameTable )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRenameTable", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRenameTable)( sesid, dbid, szName, szNameNew );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDeleteColumn(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szColumnName
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDeleteColumn ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szColumnName  );

    static PFN_JetDeleteColumn pfnJetDeleteColumn = NULL;

    if ( NULL == pfnJetDeleteColumn )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDeleteColumn = ( PFN_JetDeleteColumn ) ( GetProcAddress( hEseDll, "JetDeleteColumn" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDeleteColumn )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDeleteColumn", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDeleteColumn)( sesid, tableid, szColumnName );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDeleteColumn2(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szColumnName,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDeleteColumn2 ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szColumnName,
    const JET_GRBIT grbit  );

    static PFN_JetDeleteColumn2 pfnJetDeleteColumn2 = NULL;

    if ( NULL == pfnJetDeleteColumn2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDeleteColumn2 = ( PFN_JetDeleteColumn2 ) ( GetProcAddress( hEseDll, "JetDeleteColumn2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDeleteColumn2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDeleteColumn2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDeleteColumn2)( sesid, tableid, szColumnName, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRenameColumn(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __in JET_PCSTR  szName,
    __in JET_PCSTR  szNameNew,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRenameColumn ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __in JET_PCSTR  szName,
    __in JET_PCSTR  szNameNew,
    JET_GRBIT       grbit  );

    static PFN_JetRenameColumn pfnJetRenameColumn = NULL;

    if ( NULL == pfnJetRenameColumn )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRenameColumn = ( PFN_JetRenameColumn ) ( GetProcAddress( hEseDll, "JetRenameColumn" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRenameColumn )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRenameColumn", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRenameColumn)( sesid, tableid, szName, szNameNew, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetColumnDefaultValue(
    JET_SESID           sesid,
    JET_DBID            dbid,
    __in JET_PCSTR      szTableName,
    __in JET_PCSTR      szColumnName,
    __in_bcount(cbData) const void          *pvData,
    const unsigned long cbData,
    const JET_GRBIT     grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetColumnDefaultValue ) ( 
    JET_SESID           sesid,
    JET_DBID            dbid,
    __in JET_PCSTR      szTableName,
    __in JET_PCSTR      szColumnName,
    __in_bcount(cbData) const void          *pvData,
    const unsigned long cbData,
    const JET_GRBIT     grbit  );

    static PFN_JetSetColumnDefaultValue pfnJetSetColumnDefaultValue = NULL;

    if ( NULL == pfnJetSetColumnDefaultValue )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetColumnDefaultValue = ( PFN_JetSetColumnDefaultValue ) ( GetProcAddress( hEseDll, "JetSetColumnDefaultValue" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetColumnDefaultValue )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetColumnDefaultValue", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetColumnDefaultValue)( sesid, dbid, szTableName, szColumnName, pvData, cbData, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDeleteIndex(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __in JET_PCSTR  szIndexName
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDeleteIndex ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    __in JET_PCSTR  szIndexName  );

    static PFN_JetDeleteIndex pfnJetDeleteIndex = NULL;

    if ( NULL == pfnJetDeleteIndex )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDeleteIndex = ( PFN_JetDeleteIndex ) ( GetProcAddress( hEseDll, "JetDeleteIndex" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDeleteIndex )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDeleteIndex", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDeleteIndex)( sesid, tableid, szIndexName );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetDatabaseFileInfo(
    const char      *szDatabaseName,
    void            *pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetDatabaseFileInfo ) ( 
    const char      *szDatabaseName,
    void            *pvResult,
    unsigned long   cbMax,
    unsigned long   InfoLevel  );

    static PFN_JetGetDatabaseFileInfo pfnJetGetDatabaseFileInfo = NULL;

    if ( NULL == pfnJetGetDatabaseFileInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetDatabaseFileInfo = ( PFN_JetGetDatabaseFileInfo ) ( GetProcAddress( hEseDll, "JetGetDatabaseFileInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetDatabaseFileInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetDatabaseFileInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetDatabaseFileInfo)( szDatabaseName, pvResult, cbMax, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOpenDatabase(
    JET_SESID       sesid,
    const char      *szFilename,
    const char      *szConnect,
    JET_DBID        *pdbid,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOpenDatabase ) ( 
    JET_SESID       sesid,
    const char      *szFilename,
    const char      *szConnect,
    JET_DBID        *pdbid,
    JET_GRBIT       grbit  );

    static PFN_JetOpenDatabase pfnJetOpenDatabase = NULL;

    if ( NULL == pfnJetOpenDatabase )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOpenDatabase = ( PFN_JetOpenDatabase ) ( GetProcAddress( hEseDll, "JetOpenDatabase" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOpenDatabase )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOpenDatabase", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOpenDatabase)( sesid, szFilename, szConnect, pdbid, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOpenTable(
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    const void      *pvParameters,
    unsigned long   cbParameters,
    JET_GRBIT       grbit,
    JET_TABLEID     *ptableid
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOpenTable ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    const void      *pvParameters,
    unsigned long   cbParameters,
    JET_GRBIT       grbit,
    JET_TABLEID     *ptableid  );

    static PFN_JetOpenTable pfnJetOpenTable = NULL;

    if ( NULL == pfnJetOpenTable )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOpenTable = ( PFN_JetOpenTable ) ( GetProcAddress( hEseDll, "JetOpenTable" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOpenTable )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOpenTable", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOpenTable)( sesid, dbid, szTableName, pvParameters, cbParameters, grbit, ptableid );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetCurrentIndex(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szIndexName
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetCurrentIndex ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szIndexName  );

    static PFN_JetSetCurrentIndex pfnJetSetCurrentIndex = NULL;

    if ( NULL == pfnJetSetCurrentIndex )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetCurrentIndex = ( PFN_JetSetCurrentIndex ) ( GetProcAddress( hEseDll, "JetSetCurrentIndex" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetCurrentIndex )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetCurrentIndex", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetCurrentIndex)( sesid, tableid, szIndexName );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetCurrentIndex2(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szIndexName,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetCurrentIndex2 ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szIndexName,
    JET_GRBIT       grbit  );

    static PFN_JetSetCurrentIndex2 pfnJetSetCurrentIndex2 = NULL;

    if ( NULL == pfnJetSetCurrentIndex2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetCurrentIndex2 = ( PFN_JetSetCurrentIndex2 ) ( GetProcAddress( hEseDll, "JetSetCurrentIndex2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetCurrentIndex2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetCurrentIndex2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetCurrentIndex2)( sesid, tableid, szIndexName, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetCurrentIndex3(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szIndexName,
    JET_GRBIT       grbit,
    unsigned long   itagSequence
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetCurrentIndex3 ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szIndexName,
    JET_GRBIT       grbit,
    unsigned long   itagSequence  );

    static PFN_JetSetCurrentIndex3 pfnJetSetCurrentIndex3 = NULL;

    if ( NULL == pfnJetSetCurrentIndex3 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetCurrentIndex3 = ( PFN_JetSetCurrentIndex3 ) ( GetProcAddress( hEseDll, "JetSetCurrentIndex3" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetCurrentIndex3 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetCurrentIndex3", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetCurrentIndex3)( sesid, tableid, szIndexName, grbit, itagSequence );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetSetCurrentIndex4(
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szIndexName,
    JET_INDEXID     *pindexid,
    JET_GRBIT       grbit,
    unsigned long   itagSequence
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetSetCurrentIndex4 ) ( 
    JET_SESID       sesid,
    JET_TABLEID     tableid,
    const char      *szIndexName,
    JET_INDEXID     *pindexid,
    JET_GRBIT       grbit,
    unsigned long   itagSequence  );

    static PFN_JetSetCurrentIndex4 pfnJetSetCurrentIndex4 = NULL;

    if ( NULL == pfnJetSetCurrentIndex4 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetSetCurrentIndex4 = ( PFN_JetSetCurrentIndex4 ) ( GetProcAddress( hEseDll, "JetSetCurrentIndex4" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetSetCurrentIndex4 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetSetCurrentIndex4", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetSetCurrentIndex4)( sesid, tableid, szIndexName, pindexid, grbit, itagSequence );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetCompact(
    JET_SESID       sesid,
    const char      *szDatabaseSrc,
    const char      *szDatabaseDest,
    JET_PFNSTATUS   pfnStatus,
    JET_CONVERT     *pconvert,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetCompact ) ( 
    JET_SESID       sesid,
    const char      *szDatabaseSrc,
    const char      *szDatabaseDest,
    JET_PFNSTATUS   pfnStatus,
    JET_CONVERT     *pconvert,
    JET_GRBIT       grbit  );

    static PFN_JetCompact pfnJetCompact = NULL;

    if ( NULL == pfnJetCompact )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetCompact = ( PFN_JetCompact ) ( GetProcAddress( hEseDll, "JetCompact" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetCompact )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetCompact", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetCompact)( sesid, szDatabaseSrc, szDatabaseDest, pfnStatus, pconvert, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDefragment(
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    unsigned long   *pcPasses,
    unsigned long   *pcSeconds,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDefragment ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    unsigned long   *pcPasses,
    unsigned long   *pcSeconds,
    JET_GRBIT       grbit  );

    static PFN_JetDefragment pfnJetDefragment = NULL;

    if ( NULL == pfnJetDefragment )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDefragment = ( PFN_JetDefragment ) ( GetProcAddress( hEseDll, "JetDefragment" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDefragment )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDefragment", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDefragment)( sesid, dbid, szTableName, pcPasses, pcSeconds, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDefragment2(
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    unsigned long   *pcPasses,
    unsigned long   *pcSeconds,
    JET_CALLBACK    callback,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDefragment2 ) ( 
    JET_SESID       sesid,
    JET_DBID        dbid,
    const char      *szTableName,
    unsigned long   *pcPasses,
    unsigned long   *pcSeconds,
    JET_CALLBACK    callback,
    JET_GRBIT       grbit  );

    static PFN_JetDefragment2 pfnJetDefragment2 = NULL;

    if ( NULL == pfnJetDefragment2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDefragment2 = ( PFN_JetDefragment2 ) ( GetProcAddress( hEseDll, "JetDefragment2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDefragment2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDefragment2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDefragment2)( sesid, dbid, szTableName, pcPasses, pcSeconds, callback, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetDefragment3(
    JET_SESID       vsesid,
    const char      *szDatabaseName,
    const char      *szTableName,
    unsigned long   *pcPasses,
    unsigned long   *pcSeconds,
    JET_CALLBACK    callback,
    void            *pvContext,
    JET_GRBIT       grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetDefragment3 ) ( 
    JET_SESID       vsesid,
    const char      *szDatabaseName,
    const char      *szTableName,
    unsigned long   *pcPasses,
    unsigned long   *pcSeconds,
    JET_CALLBACK    callback,
    void            *pvContext,
    JET_GRBIT       grbit  );

    static PFN_JetDefragment3 pfnJetDefragment3 = NULL;

    if ( NULL == pfnJetDefragment3 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetDefragment3 = ( PFN_JetDefragment3 ) ( GetProcAddress( hEseDll, "JetDefragment3" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetDefragment3 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetDefragment3", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetDefragment3)( vsesid, szDatabaseName, szTableName, pcPasses, pcSeconds, callback, pvContext, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetUpgradeDatabase(
    JET_SESID       sesid,
    const char      *szDbFileName,
    const char      *szSLVFileName,
    const JET_GRBIT grbit
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetUpgradeDatabase ) ( 
    JET_SESID       sesid,
    const char      *szDbFileName,
    const char      *szSLVFileName,
    const JET_GRBIT grbit  );

    static PFN_JetUpgradeDatabase pfnJetUpgradeDatabase = NULL;

    if ( NULL == pfnJetUpgradeDatabase )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetUpgradeDatabase = ( PFN_JetUpgradeDatabase ) ( GetProcAddress( hEseDll, "JetUpgradeDatabase" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetUpgradeDatabase )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetUpgradeDatabase", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetUpgradeDatabase)( sesid, szDbFileName, szSLVFileName, grbit );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetBackup(
    const char *szBackupPath,
    JET_GRBIT grbit,
    JET_PFNSTATUS pfnStatus
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetBackup ) (  const char *szBackupPath, JET_GRBIT grbit, JET_PFNSTATUS pfnStatus  );

    static PFN_JetBackup pfnJetBackup = NULL;

    if ( NULL == pfnJetBackup )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetBackup = ( PFN_JetBackup ) ( GetProcAddress( hEseDll, "JetBackup" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetBackup )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetBackup", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetBackup)( szBackupPath, grbit, pfnStatus );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetBackupInstance(
    JET_INSTANCE    instance,
    const char      *szBackupPath,
    JET_GRBIT       grbit,
    JET_PFNSTATUS   pfnStatus
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetBackupInstance ) (  
        JET_INSTANCE    instance,
        const char      *szBackupPath,
        JET_GRBIT       grbit,
        JET_PFNSTATUS   pfnStatus  );

    static PFN_JetBackupInstance pfnJetBackupInstance = NULL;

    if ( NULL == pfnJetBackupInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetBackupInstance = ( PFN_JetBackupInstance ) ( GetProcAddress( hEseDll, "JetBackupInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetBackupInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetBackupInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetBackupInstance)( instance, szBackupPath, grbit, pfnStatus );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRestore(
    __in JET_PCSTR      sz,
    JET_PFNSTATUS       pfn
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRestore ) ( 
    __in JET_PCSTR      sz,
    JET_PFNSTATUS       pfn  );

    static PFN_JetRestore pfnJetRestore = NULL;

    if ( NULL == pfnJetRestore )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRestore = ( PFN_JetRestore ) ( GetProcAddress( hEseDll, "JetRestore" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRestore )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRestore", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRestore)( sz, pfn );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRestore2(
    JET_PCSTR           sz,
    JET_PCSTR           szDest,
    JET_PFNSTATUS       pfn
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRestore2 ) ( 
    JET_PCSTR           sz,
    JET_PCSTR           szDest,
    JET_PFNSTATUS       pfn  );

    static PFN_JetRestore2 pfnJetRestore2 = NULL;

    if ( NULL == pfnJetRestore2 )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRestore2 = ( PFN_JetRestore2 ) ( GetProcAddress( hEseDll, "JetRestore2" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRestore2 )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRestore2", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRestore2)( sz, szDest, pfn );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetRestoreInstance(
    JET_INSTANCE instance,
    const char *sz,
    const char *szDest,
    JET_PFNSTATUS pfn
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetRestoreInstance ) (     
        JET_INSTANCE instance,
        const char *sz,
        const char *szDest,
        JET_PFNSTATUS pfn  );

    static PFN_JetRestoreInstance pfnJetRestoreInstance = NULL;

    if ( NULL == pfnJetRestoreInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetRestoreInstance = ( PFN_JetRestoreInstance ) ( GetProcAddress( hEseDll, "JetRestoreInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetRestoreInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetRestoreInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetRestoreInstance)( instance, sz, szDest, pfn );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOpenFile(
    const char *szFileName,
    JET_HANDLE  *phfFile,
    unsigned long *pulFileSizeLow,
    unsigned long *pulFileSizeHigh
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOpenFile ) (  const char *szFileName,
    JET_HANDLE  *phfFile,
    unsigned long *pulFileSizeLow,
    unsigned long *pulFileSizeHigh  );

    static PFN_JetOpenFile pfnJetOpenFile = NULL;

    if ( NULL == pfnJetOpenFile )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOpenFile = ( PFN_JetOpenFile ) ( GetProcAddress( hEseDll, "JetOpenFile" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOpenFile )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOpenFile", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOpenFile)( szFileName, phfFile, pulFileSizeLow, pulFileSizeHigh );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOpenFileInstance(
    JET_INSTANCE instance,
    const char *szFileName,
    JET_HANDLE  *phfFile,
    unsigned long *pulFileSizeLow,
    unsigned long *pulFileSizeHigh
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOpenFileInstance ) (  JET_INSTANCE instance,
                const char *szFileName,
                JET_HANDLE  *phfFile,
                unsigned long *pulFileSizeLow,
                unsigned long *pulFileSizeHigh  );

    static PFN_JetOpenFileInstance pfnJetOpenFileInstance = NULL;

    if ( NULL == pfnJetOpenFileInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOpenFileInstance = ( PFN_JetOpenFileInstance ) ( GetProcAddress( hEseDll, "JetOpenFileInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOpenFileInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOpenFileInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOpenFileInstance)( instance, szFileName, phfFile, pulFileSizeLow, pulFileSizeHigh );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetOpenFileSectionInstance(
    JET_INSTANCE    instance,
    __in JET_PSTR   szFile,
    JET_HANDLE *    phFile,
    long        iSection,
    long        cSections,
    unsigned long * pulSectionSizeLow,
    long *      plSectionSizeHigh
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetOpenFileSectionInstance ) ( 
    JET_INSTANCE    instance,
    __in JET_PSTR   szFile,
    JET_HANDLE *    phFile,
    long        iSection,
    long        cSections,
    unsigned long * pulSectionSizeLow,
    long *      plSectionSizeHigh  );

    static PFN_JetOpenFileSectionInstance pfnJetOpenFileSectionInstance = NULL;

    if ( NULL == pfnJetOpenFileSectionInstance )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetOpenFileSectionInstance = ( PFN_JetOpenFileSectionInstance ) ( GetProcAddress( hEseDll, "JetOpenFileSectionInstance" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetOpenFileSectionInstance )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetOpenFileSectionInstance", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetOpenFileSectionInstance)( instance, szFile, phFile, iSection, cSections, pulSectionSizeLow, plSectionSizeHigh );
    goto Cleanup;
Cleanup:

    return err;
}



JET_ERR
BounceJetGetLogFileInfo(
    char *szLog,
    __out_bcount(cbMax) void *pvResult,
    const unsigned long cbMax,
    const unsigned long InfoLevel
)
{
    JET_ERR     err = JET_errSuccess;

    typedef JET_ERR ( __stdcall *PFN_JetGetLogFileInfo ) (  char *szLog, 
    __out_bcount(cbMax) void *pvResult,
    const unsigned long cbMax,
    const unsigned long InfoLevel  );

    static PFN_JetGetLogFileInfo pfnJetGetLogFileInfo = NULL;

    if ( NULL == pfnJetGetLogFileInfo )
    {
        const HMODULE       hEseDll = HmodEsetestEseDll();

        if ( NULL != hEseDll )
        {
            pfnJetGetLogFileInfo = ( PFN_JetGetLogFileInfo ) ( GetProcAddress( hEseDll, "JetGetLogFileInfo" ) );
        }
        if ( NULL == hEseDll || NULL == pfnJetGetLogFileInfo )
        {
            tprintf( "%s(): Failed to either fetch hEseDll (=%p) GetProcAddress( hEseDll, %s ), Gle = %d " CRLF,
                __FUNCTION__, hEseDll, "JetGetLogFileInfo", GetLastError() );
            err = JET_errTestError;
            goto Cleanup;
        }
    }

    err = (*pfnJetGetLogFileInfo)( szLog, pvResult, cbMax, InfoLevel );
    goto Cleanup;
Cleanup:

    return err;
}



bool FEsetestAlwaysNarrow()
{
    return true;
}


