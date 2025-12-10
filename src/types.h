#pragma once



#include <stdio.h>


#ifndef UNICODE
#define UNICODE
#endif


#define NUMBER_OF_BYTES_IN_ENTRY 80
#define MAX_FILE_NAME_LENGTH     60


// Windows-compatible types.
typedef unsigned char     BYTE;
typedef unsigned short    WORD;
typedef unsigned long     DWORD;
typedef unsigned __int64  DWORD_PTR;
typedef long              LONG;
typedef __int64           LONGLONG;
typedef unsigned __int64  ULONGLONG;
typedef unsigned __int64  ULONG_PTR;



// Windows-compatible macros.
#define MAKEWORD(a,b) ((WORD) (((BYTE)  (((DWORD_PTR) (a)) & 0xff)) | ((WORD) ((BYTE) (((DWORD_PTR) (b)) & 0xff))) << 8))
#define MAKELONG(a,b) ((LONG) (((WORD)  (((DWORD_PTR) (a)) & 0xffff)) | ((DWORD) ((WORD) (((DWORD_PTR) (b)) & 0xffff))) << 16))
#define MAKELONGLONG(a,b)  ((LONGLONG)  ((((DWORD) (a)) & 0xffffffff) | ((((DWORD) (b)) & 0xffffffff)) << 32))
#define MAKEULONGLONG(a,b) ((ULONGLONG) ((((DWORD) (a)) & 0xffffffff) | ((((DWORD) (b)) & 0xffffffff)) << 32))



/**
 * Enumeration of all supported file types.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param unrecognized  unrecognized parameter
 * @param exec_pe  pe executable format(Winx86)
 * @param exec_pep  pe+ executable format(Winx64)
 * 
 * 
 * @since 1.0.0
 */
static const enum ESupportedTypes
{
    unrecognized = 0,
    exec_pe      = 1,
    exec_pep     = 2,

};



/**
 * Enumeration of all supported file extensions.
 * 
 * @author Ilya Alexandrovich
 * 
 * 
 * 
 * @since 1.0.0
 */
static const enum ESupportedExtensions
{
    unrecognized = 0,
    exe          = 1
} supportedextensions;
