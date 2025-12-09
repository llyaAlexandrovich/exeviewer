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
