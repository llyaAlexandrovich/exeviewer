#pragma once



#include <stdbool.h>


#include "../../types.h"
#include "winexe_consts.h"
#include "winexe_structures.h"
#include "winexe_struct_filler_functions.h"



/**
 * Print out DOS stub text.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER
 * @param buffer  file buffer
 * 
 * @since 1.0.0
 */
void PrintDOSStubText(IMAGE_DOS_HEADER* idh, char* buffer);



/**
 * Print out readable data from all executable headers.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure
 * @param inh  pointer to IMAGE_NT_HEADERS32 or IMAGE_NT_HEADERS64 structure
 * @param buffer  file buffer
 * @param arch  type of the executable(x64 | x32) to use
 * 
 * @since 1.0.0
 */
void PrintHeadersData(IMAGE_DOS_HEADER* idh, void* inh, char* buffer, int arch);



/**
 * Print out readable data from IMAGE_NT_HEADERS64 structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param inh  pointer to IMAGE_NT_HEADERS64 structure
 * 
 * @since 1.0.0
 */
void PrintNTHeaderLow(IMAGE_NT_HEADERS64* inh);



/**
 * Print out readable data from IMAGE_NT_HEADERS32 structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param inh  pointer to IMAGE_NT_HEADERS32 structure
 * 
 * @since 1.0.0
 */
void PrintNTHeaderHigh(IMAGE_NT_HEADERS32* inh);



/**
 * Print out readable data from IMAGE_DATA_DIRECTORY structure entry.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idd  pointer to IMAGE_DATA_DIRECTORY structure
 * 
 * @since 1.0.0
 */
void PrintNTDataDirectoryHeader(IMAGE_DATA_DIRECTORY* idd);



/**
 * Print out readable data from DOS header(IMAGE_DOS_HEADER structutre).
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure
 * @param buffer  file buffer
 * 
 * @since 1.0.0
 */
void PrintDOSHeader(IMAGE_DOS_HEADER* idh, char* buffer);



/**
 *  Determine whether file format is PE or PE+.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param buffer  file buffer
 * 
 * @return return -1 in error otherwise IMAGE_PE_TYPE or IMAGE_PEP_TYPE
 * 
 * @since 1.0.0
 */
int DeterminePEFormat(char* buffer);



/**
 * Check if file is Windows executable.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param buffer  file buffer
 * 
 * @return return true if file is PE executable otherwise false
 * 
 * @since 1.0.0
 */
bool bIsFilePEExecutable(char* buffer);
