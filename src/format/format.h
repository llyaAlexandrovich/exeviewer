#pragma once



#include <stdio.h>



#include "../types.h"
#include "../formats/win-exe/winexe.h"



/**
 * Enumeration of all supported file types.
 * 
 * @author  Ilya Alexandrovich
 * 
 * @param unrecognized  unrecognized parameter
 * @param exec_pe       pe executable format(Winx86)
 * @param exec_pep      pe+ executable format(Winx64)
 * 
 * 
 * @since  1.0.0
 */
const enum ESupportedTypes
{
    unrecognized = 0,
    exec_pe      = 1,
    exec_pep     = 2,

};



/**
 * Recognize file format.
 * 
 * @author  Ilya Alexandrovich
 * 
 * @param buffer  file buffer with at least 80 bytes
 * of file data
 * 
 * @return  return -1 in error otherwise ESupportedTypes::value
 * 
 * @since  1.0.0
 */
int RecognizeFileFormat(char* buffer);



/**
 * Recognize PE format.
 * 
 * @author  Ilya Alexandrovich
 * 
 * @param buffer  data buffer
 * 
 * @return  return -1 in error otherwise ESupportedTypes::value
 * 
 * @since 1.0.0
 */
int RecognizePEFormat(char* buffer);