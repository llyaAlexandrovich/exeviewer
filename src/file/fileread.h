#pragma once



#include <stdio.h>
#include <string.h>


#include "../types.h"






/**
 * Read entry part of the file by the given file name.
 * In current context entry part equals to 80 bytes.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  pointer to char buffer containing
 * name of the file required to read
 * @param filebuffer  pointer to the buffer in which to
 * write data from the file
 * 
 * @return return -1 in error otherwise 0
 * 
 * @since 1.0.0
*/
int ReadFileEntry(char* const filename, char* filebuffer);



/**
 * Read file by the given name into the given buffer fully. 
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  pointer to char buffer containing
 * name of the file required to read
 * @param filebuffer  pointer to the buffer in which to
 * write data from the file
 * 
 * @return return -1 in error otherwise 0
 * 
 * @since 1.0.0
*/
int ReadFile(char* const filename, char* filebuffer);



/**
 * Get file size by the given name.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  pointer to char buffer containing
 * name of the file required to read
 * 
 * @return return 0 in error otherwise file size
 * 
 * @since 1.0.0
*/
unsigned long long GetFileSize(char* const filename);



/**
 * Get extension from a file name.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  pointer to the buffer with file name
 * 
 * @return return -1 in error otherwise ESupportedTypes::value
 */
int GetFileExtension(char* const filename);
