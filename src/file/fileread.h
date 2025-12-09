#pragma once



#include <stdio.h>


#include "../types.h"






/**
 * Read entry part of the file by the given file name.
 * In current context entry part equals to 80 bytes.
 * 
 * @author  Ilya Alexandrovich
 * 
 * @param filename  pointer to char buffer containing
 * name of the file required to read.
 * @param filebuffer  pointer to the buffer in which to
 * write data from the file.
 * 
 * @return  return -1 in error otherwise 0.
 * 
 * @since  1.0.0
*/
int ReadFileEntry(const char* filename, char* filebuffer);



/**
 * Read file by the given name into the given buffer fully. 
 * 
 * @author  Ilya Alexandrovich
 * 
 * @param filename  pointer to char buffer containing
 * name of the file required to read.
 * @param filebuffer  pointer to the buffer in which to
 * write data from the file.
 * 
 * @return  return -1 in error otherwise 0.
 * 
 * @since  1.0.0
*/
int ReadFile(const char* filename, char* filebuffer);



/**
 * Get file size by the given name.
 * 
 * @author  Ilya Alexandrovich
 * 
 * @param filename  pointer to char buffer containing
 * name of the file required to read.
 * 
 * @return  return -1 in error otherwise file size.
 * 
 * @since  1.0.0
*/
unsigned long long GetFileSize(const char* filename);