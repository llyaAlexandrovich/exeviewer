#pragma once



#include <stdbool.h>


#include "../../types.h"
#include "winexe_structures.h"
#include "winexe_struct_filler_functions.h"



/**
 * Print out DOS stub text.
 * 
 * @author  Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER
 * @param buffer  file buffer
 * 
 * @since  1.0.0
 */
void PrintDOSStubText(IMAGE_DOS_HEADER* idh, char* buffer);



/**
 *  Determine whether file format is PE or PE+.
 * 
 * @author  Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER
 * @param buffer  file buffer
 * 
 * @return  return -1 in error otherwise 0
 * 
 * @since  1.0.0
 */
int DeterminePEFormat(IMAGE_DOS_HEADER* idh, char* buffer);



/**
 * Check if file is Windows executable.
 * 
 * @author  Ilya Alexandrovich
 * 
 * @param buffer  file buffer
 * 
 * @return  return true if file is PE executable otherwise false
 * 
 * @since  1.0.0
 */
bool bIsFilePEExecutable(char* buffer);
