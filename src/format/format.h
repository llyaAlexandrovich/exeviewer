#pragma once



#include <stdio.h>



#include "../types.h"
#include "../formats/win-exe/winexe.h"




/**
 * Recognize file format.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param buffer  file buffer with at least 80 bytes
 * of file data
 * 
 * @return return -1 in error otherwise ESupportedTypes::value
 * 
 * @since 1.0.0
 */
int RecognizeFileFormat(char* buffer);
