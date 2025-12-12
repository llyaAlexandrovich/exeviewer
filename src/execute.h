#pragma once



#include <stdio.h>


#include "types.h"
#include "formats/win-exe/winexe.h"
#include "file/fileread.h"




/**
 * Trying to start exeviewer on specified file.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  file name to try exeviewer on
 * 
 * @since 1.0.0
 */
void TryExecuteViewer(char* const filename);



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
