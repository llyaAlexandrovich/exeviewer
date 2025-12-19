#pragma once



#include <stdio.h>
#include <stdlib.h>
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
 * @return return EXIT_FAILURE in error otherwise EXIT_SUCCESS
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
 * @return return EXIT_FAILURE in error otherwise EXIT_SUCCESS
 * 
 * @since 1.0.0
*/
int ReadFileInternal(char* const filename, char* filebuffer);



/**
 * Get file size by the given name.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  pointer to char buffer containing
 * name of the file required to read
 * @param filesize  pointer to a variable into which the result 
 * will be written
 * 
 * @return return EXIT_FAILURE in error otherwise EXIT_SUCCESS
 * 
 * @since 1.0.0
*/
int GetFileSize(char* const filename, unsigned long long* filesize);



/**
 * Get extension from a file name.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  pointer to the buffer with file name
 * @param fileext  pointer to a variable into which the result 
 * will be written
 * 
 * @return return EXIT_FAILURE in error otherwise EXIT_SUCCESS
 */
int GetFileExtension(char* const filename, int* fileext);
