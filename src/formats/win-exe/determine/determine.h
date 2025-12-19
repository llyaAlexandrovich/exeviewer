#pragma once



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#include "../../../types.h"
#include "../winexe_consts.h"
#include "../winexe_structures.h"


// Determine IMAGE_NT_HEADERS::IMAGE_FILE_HEADER::MACHINE type.
#define DETERMINE_MACHINE(x) (x == IMAGE_FILE_MACHINE_UNKNOWN ? "MACHINE_UNKNOWN" : x == IMAGE_FILE_MACHINE_I386 ? "MACHINE_I386"\
 : x == IMAGE_FILE_MACHINE_R3000BE ? "MACHINE_R3000BE" : x == IMAGE_FILE_MACHINE_R3000 ? "MACHINE_R3000" : x == IMAGE_FILE_MACHINE_R4000\
 ? "MACHINE_R4000" : x == IMAGE_FILE_MACHINE_R10000 ? "MACHINE_R10000" : x == IMAGE_FILE_MACHINE_WCEMIPSV2 ? "MACHINE_WCEMIPSV2"\
 : x == IMAGE_FILE_MACHINE_ALPHA ? "MACHINE_ALPHA" : x == IMAGE_FILE_MACHINE_SH3 ? "MACHINE_SH3" : x == IMAGE_FILE_MACHINE_SH3DSP ?\
 "MACHINE_SH3DSP" : x == IMAGE_FILE_MACHINE_SH3E ? "MACHINE_SH3E" : x == IMAGE_FILE_MACHINE_SH4 ? "MACHINE_SH4" : x == IMAGE_FILE_MACHINE_SH5\
 ? "MACHINE_SH5" : x == IMAGE_FILE_MACHINE_ARM ? "MACHINE_ARM" : x == IMAGE_FILE_MACHINE_THUMB ? "MACHINE_THUMB" : x == IMAGE_FILE_MACHINE_ARMNT\
 ? "MACHINE_ARMNT" : x == IMAGE_FILE_MACHINE_AM33 ? "MACHINE_AM33" : x == IMAGE_FILE_MACHINE_POWERPC ? "MACHINE_POWERPC" : x == IMAGE_FILE_MACHINE_POWERPCFP\
 ? "MACHINE_POWERPCFP" : x == IMAGE_FILE_MACHINE_IA64 ? "MACHINE_IA64" : x == IMAGE_FILE_MACHINE_MIPS16 ? "MACHINE_MIPS16" : x == IMAGE_FILE_MACHINE_ALPHA64\
 ? "MACHINE_ALPHA64|MACHINE_AXP64" : x == IMAGE_FILE_MACHINE_MIPSFPU ? "MACHINE_MIPSFPU" : x == IMAGE_FILE_MACHINE_MIPSFPU16 ? "MACHINE_MIPSFPU16"\
 : x == IMAGE_FILE_MACHINE_EBC ? "MACHINE_EBC" : x == IMAGE_FILE_MACHINE_AMD64 ? "MACHINE_AMD64" : x == IMAGE_FILE_MACHINE_M32R ? "MACHINE_M32R"\
 : x == IMAGE_FILE_MACHINE_ARM64 ? "MACHINE_ARM64" : "MACHINE_UNKNOWN")



/**
 * Determine timedate stamp since epoch to readable format.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param t  time since epoch
 * 
 * @return pointer to the char buffer containing readable timedate
 * 
 * @since 1.0.8
 */
char* DetermineTimeDateStamp(DWORD t);



/**
 * Determine executable file characteristics.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param characteristics  executable file characteristics. note that
 * value is volatile type. it required because otherwise -O3 compiler
 * option will overoptimize it and at some point this value will mot 
 * be accessible and therefore program will not proceed correctly.
 * 
 * @return pointer to the char buffer containing readable file characteristics
 * 
 * @since 1.0.8
 */
void DetermineCharacteristics(volatile DWORD characteristics);
