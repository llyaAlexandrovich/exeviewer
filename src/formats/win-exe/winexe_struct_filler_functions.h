#pragma once



#include <stdio.h>


#include "../../types.h"
#include "winexe_consts.h"
#include "winexe_structures.h"




/**
 * Perform reading and processing all the data from the file.
 * recognized as Windows executable x32.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IAMGE_DOS_HEADER structure
 * @param inh  pointer to IMAGE_NT_HEADERS32 structure
 * @param buffer  file buffer
 * 
 * @since 1.0.6
 */
void FillOutNTEntireStructureLow(IMAGE_DOS_HEADER* idh, IMAGE_NT_HEADERS32* inh, char* buffer);



/**
 * Perform reading and processing all the data from the file.
 * recognized as Windows executable x64.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IAMGE_DOS_HEADER structure
 * @param inh  pointer to IMAGE_NT_HEADERS32 structure
 * @param buffer  file buffer
 * 
 * @since 1.0.6
 */
void FillOutNTEntireStructureHigh(IMAGE_DOS_HEADER* idh, IMAGE_NT_HEADERS64* inh, char* buffer);



/**
 * Fill out IMAGE_DOS_HEADER structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure
 * @param buffer  file buffer
 * 
 * @since 1.0.0
 */
void FillOutDOSHeader(IMAGE_DOS_HEADER* idh, char* buffer);



/**
 * Fill out IMAGE_NT_HEADERS32 structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure
 * @param buffer  file buffer
 * @param inh  pointer to IMAGE_NT_HEADERS32 structure
 * 
 * @since 1.0.6
 */
void FillOutNTHeaderLow(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_NT_HEADERS32* inh);



/**
 * Fill out IMAGE_NT_HEADERS64 structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure
 * @param buffer  file buffer
 * @param inh  pointer to IMAGE_NT_HEADERS64 structure
 * 
 * @since 1.0.6
 */
void FillOutNTHeaderHigh(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_NT_HEADERS64* inh);



/** 
 * Fill out IMAGE_OPTIONAL_HEADER32 structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER
 * @param buffer  file buffer
 * @param ioh  pointer to IMAGE_OPTIONAL_HEADER32 structure
 * 
 * @since 1.0.0
*/
void FillOutNTOptionalHeaderLow(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_OPTIONAL_HEADER32* ioh);



/** 
 * Fill out IMAGE_OPTIONAL_HEADER64 structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER
 * @param buffer  file buffer
 * @param ioh  pointer to IMAGE_OPTIONAL_HEADER64 structure
 * 
 * @since 1.0.0
*/
void FillOutNTOptionalHeaderHigh(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_OPTIONAL_HEADER64* ioh);



/**
 * Fill out IMAGE_FILE_HEADER structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure
 * @param buffer  file buffer
 * @param ifh  pointer to IMAGE_FILE_HEADER structure
 * 
 * @since 1.0.0
 */
void FillOutNTFileHeader(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_FILE_HEADER* ifh);



/**
 * Fill out IMAGE_DATA_DIRECTORY structure for x64.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure
 * @param buffer  file buffer
 * @param idd  pointer to IMAGE_DATA_DIRECTORY structure
 * 
 * @since 1.0.0
 */
void FillOutNTDataDirectoryHeaderHigh(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_DATA_DIRECTORY* idd);



/**
 * Fill out IMAGE_DATA_DIRECTORY structure for x32.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure
 * @param buffer  file buffer
 * @param idd  pointer to IMAGE_DATA_DIRECTORY structure
 * 
 * @since 1.0.0
 */
void FillOutNTDataDirectoryHeaderLow(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_DATA_DIRECTORY* idd);



/**
 * Fill out IMAGE_DATA_DIRECTORY structure and IMAGE_SECTION_HEADER for every instance
 * of IMAGE_DATA_DIRECTORY structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure
 * @param buffer  file buffer
 * @param inh  pointer to IMAGE_NT_HEADERS32 structure
 * @param ish  pointer to IMAGE_SECTION_HEADER structure
 * 
 * @since 1.0.6
 */
void FillOutDataSectionLow(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_NT_HEADERS32* inh, IMAGE_SECTION_HEADER* ish);



/**
 * Fill out IMAGE_DATA_DIRECTORY structure and IMAGE_SECTION_HEADER for every instance
 * of IMAGE_DATA_DIRECTORY structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure
 * @param buffer  file buffer
 * @param inh  pointer to IMAGE_NT_HEADERS64 structure
 * @param ish  pointer to IMAGE_SECTION_HEADER structure
 * 
 * @since 1.0.6
 */
void FillOutDataSectionHigh(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_NT_HEADERS64* inh, IMAGE_SECTION_HEADER* ish);
