#pragma once



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "../types.h"
#include "../exeviewer/exeviewer.h"
#include "../formats/win-exe/winexe.h"
#include "../file/fileread.h"


typedef struct _PEExecutablesData
{
    IMAGE_DOS_HEADER* idh;
    bool       doshowless;
    bool     supportcheck;
    char*          buffer;
    char*        filename;
    union
    {
        IMAGE_NT_HEADERS32* low;
        IMAGE_NT_HEADERS64* high;
    } inh;
    int              arch;
} PEExecutablesData;



/**
 * Trying to start exeviewer on specified file.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  file name to try exeviewer on
 * 
 * @return return -1 in error, 0 in success 1 if file was not recognized
 * 
 * @since 1.0.0
 */
int TryExecuteViewer(char* const filename, bool doshowless, bool supportcheck);



/**
 * Checking if file size is above NUMBER_OF_BYTES_IN_ENTRY
 * to have ability to execute it properly.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  name of the file to check size of
 * 
 * @return return 0 in error otherwise returns file size
 * 
 * @since 1.0.0
 * 
 */
unsigned long long CheckFileSize(char* const filename);



/**
 * Check type of the given file.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  name of the file to check on
 * @param buffer  file buffer
 * 
 * @return return -1 in error otherwise ESupportedTypes::value
 * 
 * @since 1.0.0
 */
int CheckFileType(char* const filename, char* buffer);



/**
 * Get filled information structure of the given file.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param pex  pointer to PEExecutablesData structure
 * 
 * @since 1.0.0
 */
void GetInfoOfPEExecutable(PEExecutablesData* pex);
