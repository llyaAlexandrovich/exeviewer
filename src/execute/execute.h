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
    IMAGE_DOS_HEADER  idh;
    bool       doshowless;
    bool     supportcheck;
    char*          buffer;
    char*        filename;
    union
    {
        IMAGE_NT_HEADERS32 low;
        IMAGE_NT_HEADERS64 high;
    } inh;
    int              arch;
} PEExecutablesData;



/**
 * Trying to start exeviewer on specified file.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  file name to try exeviewer on
 * @param doshowless  bool argument specified to whether to
 * write data into terminal or keep it clean
 * @param supportcheck  check whether executable could
 * run in current system
 * 
 * @return return EXIT_FAILURE in error, EXIT_SUCCESS in success
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
 * @param filesize  pointer to a variable into which the 
 * result will be written
 * 
 * @return return EXIT_FAILURE in error otherwise EXIT_SUCCESS
 * 
 * @since 1.0.0
 * 
 */
int CheckFileSize(char* const filename, unsigned long long* filesize);



/**
 * Determine type of the given file.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  name of the file to check on
 * @param buffer  file buffer
 * @param filetype  pointer to a variable into which the 
 * result will be written
 * 
 * @return return EXIT_FAILURE in error otherwise ESupportedTypes::value
 * 
 * @since 1.0.0
 */
int DetermineFileType(char* const filename, char* buffer, int* filetype);



/**
 * Get information about given executable file.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param pex  pointer to PEExecutablesData structure
 * 
 * @since 1.0.0
 */
void GetInfoOfPEExecutable(PEExecutablesData* pds);



/**
 * Print information about executable file.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param pds  pointer to PEExecutablesData structure
 * 
 * @since 1.0.7
 */
void PrintInfoOfPEExecutable(PEExecutablesData* pds);



/**
 * Check if file is recognized and supported.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param buffer  file buffer
 * 
 * @since 1.0.7
 */
bool bIsFileRecognizedExecutable(char* buffer);
