#pragma once



#include <stdbool.h>


#include "../../types.h"
#include "winexe_consts.h"





/**
 * DOS header structure. Actually old useless stub.
 * 
 * @param e_magic  magic number
 * @param e_cblp  bytes on last page of file
 * @param e_cp  pages in file
 * @param e_crlc  relocations
 * @param e_cparhdr  size of header in paragraphs
 * @param e_minalloc  minimum extra paragraphs needed
 * @param e_maxalloc  maximum extra paragraphs needed
 * @param e_ss  initial SS value
 * @param e_sp  initial SP value
 * @param e_csum  checksum
 * @param e_ip  initial IP value
 * @param e_cs  initial CS value
 * @param e_lfarlc  file address of relocation table
 * @param e_ovno  overlay number
 * @param e_res  reserver
 * @param e_eomid  OEM identifier
 * @param e_oeminfo  OEM information
 * @param e_res2  reserved
 * @param e_lfanew  file address of new exe header
 * 
 * @since 1.0.0
 */
typedef struct _IMAGE_DOS_HEADER
{
    WORD   e_magic;
    WORD   e_cblp;
    WORD   e_cp;
    WORD   e_crlc;
    WORD   e_cparhdr;
    WORD   e_minalloc;
    WORD   e_maxalloc;
    WORD   e_ss;
    WORD   e_sp;
    WORD   e_csum;
    WORD   e_ip;
    WORD   e_cs;
    WORD   e_lfarlc;
    WORD   e_ovno;
    WORD   e_res[4];
    WORD   e_oemid;
    WORD   e_oeminfo;
    WORD   e_res2[10];
    LONG   e_lfanew;
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;



/**
 * COFF header structure.
 * 
 * @param Machine  machine type
 * @param NumberOfSections  the number of sections
 * @param TimeDateStamp  the low 32 bits of the number of seconds since epoch
 * @param PointerToSymbolTable  the file offset of the COFF symbol table
 * @param NumberOfSymbols  the number of entries in the symbol table
 * @param SizeOfOptionalHeader  the size of the optional header
 * @param Characteristics  the flags that indicate the attributes of the file
 * 
 * @since 1.0.0
 */
typedef struct _IMAGE_FILE_HEADER
{
    WORD    Machine;
    WORD    NumberOfSections;
    DWORD   TimeDateStamp;
    DWORD   PointerToSymbolTable;
    DWORD   NumberOfSymbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;



/**
 * Data Directory structure.
 * 
 * @param VirtualAddress  the address of the table relative to the base 
 * address of the image when the table is loaded
 * @param Size  size in bytes
 * 
 * @since 1.0.0
 */
typedef struct _IMAGE_DATA_DIRECTORY
{
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;



/**
 * Image Section structure.
 * 
 * @param Name
 * @param Misc
 * @param VirtualAddress
 * @param SizeOfRawData
 * @param PointerToRawData
 * @param PointerToRelocations
 * @param PointerToLinenumbers
 * @param NumberOfRelocations
 * @param NumberOfLinenumbers
 * @param Characteristics
 * 
 * @since 1.0.0
 */
typedef struct _IMAGE_SECTION_HEADER 
{
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    union
    {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    NumberOfRelocations;
    WORD    NumberOfLinenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;



/**
 * PE data header structure.
 * 
 * @param Magic  identifies the state of the image file. PE or PE+
 * @param MajorLinkerVersion  the linker major version number
 * @param MinorLinkerVersion  the linker minor version number
 * @param SizeOfCode  the size of the .text section
 * @param SizeOfInitializedData  the size of the initialized data section
 * @param SizeOfUninitializedData  the size of the .bss section
 * @param AddressOfEntryPoint  the address of the entry address
 * @param BaseOfCode  the address of the beginning-of-code section
 * @param ImageBase  the preferred address when loaded into memory
 * @param SectionAlignment  the alignment that is used when in loaded into memory
 * @param FileAlignment  raw alignment that is used to align raw data sections
 * @param MajorOperatingSystemVersion  the major version number of the required operating system
 * @param MinorOperatingSystemVersion  the minor version number of the required operating system
 * @param MajorImageVersion  the major version number of the image
 * @param MinorImageVersion  the minor version number of the image
 * @param MajorSubsystemVersion  the major version number of the subsystem
 * @param MinorSubsystemVersion  the minor version number of the subsystem
 * @param Win32VersionValue  reserved
 * @param SizeOfImage  the size of the image in bytes
 * @param SizeOfHeaders  the size of the DOS and PE headers combined
 * @param CheckSum  image file checksum
 * @param Subsystem  the subsystem that is required to run this image
 * @param DllCharacteristics  Dll characteristics
 * @param SizeOfStackReserve  the size of the stack to reserve
 * @param SizeOfStackCommit  the size of the stack to commit
 * @param SizeOfHeapReserve  the size of the local heap space to reserve
 * @param SizeOfHeapCommit  the size of the local heap space to commit
 * @param LoaderFlags  reserved
 * @param NumberOfRvaAndSizes  the number of data-directory entries in the remainder of the optional header
 * @param DataDirectory  DataDirectory structure
 * 
 * @since 1.0.0
 */
typedef struct _IMAGE_OPTIONAL_HEADER
{
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
    DWORD   BaseOfData;
    DWORD   ImageBase;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    WORD    MajorOperatingSystemVersion;
    WORD    MinorOperatingSystemVersion;
    WORD    MajorImageVersion;
    WORD    MinorImageVersion;
    WORD    MajorSubsystemVersion;
    WORD    MinorSubsystemVersion;
    DWORD   Win32VersionValue;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    DWORD   SizeOfStackReserve;
    DWORD   SizeOfStackCommit;
    DWORD   SizeOfHeapReserve;
    DWORD   SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;



/**
 * PE+ data header structure.
 * 
 * @param Magic  identifies the state of the image file. PE or PE+
 * @param MajorLinkerVersion  the linker major version number
 * @param MinorLinkerVersion  the linker minor version number
 * @param SizeOfCode  the size of the .text section
 * @param SizeOfInitializedData  the size of the initialized data section
 * @param SizeOfUninitializedData  the size of the .bss section
 * @param AddressOfEntryPoint  the address of the entry address
 * @param BaseOfCode  the address of the beginning-of-code section
 * @param ImageBase  the preferred address when loaded into memory
 * @param SectionAlignment  the alignment that is used when in loaded into memory
 * @param FileAlignment  raw alignment that is used to align raw data sections
 * @param MajorOperatingSystemVersion  the major version number of the required operating system
 * @param MinorOperatingSystemVersion  the minor version number of the required operating system
 * @param MajorImageVersion  the major version number of the image
 * @param MinorImageVersion  the minor version number of the image
 * @param MajorSubsystemVersion  the major version number of the subsystem
 * @param MinorSubsystemVersion  the minor version number of the subsystem
 * @param Win32VersionValue  reserved
 * @param SizeOfImage  the size of the image in bytes
 * @param SizeOfHeaders  the size of the DOS and PE headers combined
 * @param CheckSum  image file checksum
 * @param Subsystem  the subsystem that is required to run this image
 * @param DllCharacteristics  Dll characteristics
 * @param SizeOfStackReserve  the size of the stack to reserve
 * @param SizeOfStackCommit  the size of the stack to commit
 * @param SizeOfHeapReserve  the size of the local heap space to reserve
 * @param SizeOfHeapCommit  the size of the local heap space to commit
 * @param LoaderFlags  reserved
 * @param NumberOfRvaAndSizes  the number of data-directory entries in the remainder of the optional header
 * @param DataDirectory  DataDirectory structure
 * 
 * @since 1.0.0
 */
typedef struct _IMAGE_OPTIONAL_HEADER64
{
    WORD        Magic;
    BYTE        MajorLinkerVersion;
    BYTE        MinorLinkerVersion;
    DWORD       SizeOfCode;
    DWORD       SizeOfInitializedData;
    DWORD       SizeOfUninitializedData;
    DWORD       AddressOfEntryPoint;
    DWORD       BaseOfCode;
    ULONGLONG   ImageBase;
    DWORD       SectionAlignment;
    DWORD       FileAlignment;
    WORD        MajorOperatingSystemVersion;
    WORD        MinorOperatingSystemVersion;
    WORD        MajorImageVersion;
    WORD        MinorImageVersion;
    WORD        MajorSubsystemVersion;
    WORD        MinorSubsystemVersion;
    DWORD       Win32VersionValue;
    DWORD       SizeOfImage;
    DWORD       SizeOfHeaders;
    DWORD       CheckSum;
    WORD        Subsystem;
    WORD        DllCharacteristics;
    ULONGLONG   SizeOfStackReserve;
    ULONGLONG   SizeOfStackCommit;
    ULONGLONG   SizeOfHeapReserve;
    ULONGLONG   SizeOfHeapCommit;
    DWORD       LoaderFlags;
    DWORD       NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;



/**
 * PE header structure.
 * 
 * @param Signature  a 4-byte signature identifying the file as a PE image
 * @param FileHeader  an IMAGE_FILE_HEADER structure
 * @param OptionalHeader  an IMAGE_OPTIONAL_HEADER structure
 * 
 * @since 1.0.0
 */
typedef struct _IMAGE_NT_HEADERS64
{
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;



/**
 * PE+ header structure.
 * 
 * @param Signature  a 4-byte signature identifying the file as a PE image
 * @param FileHeader  an IMAGE_FILE_HEADER structure
 * @param OptionalHeader  an IMAGE_OPTIONAL_HEADER structure
 * 
 * @since 1.0.0
 */
typedef struct _IMAGE_NT_HEADERS
{
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;
} IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;


/**
 * Universal union for containing whether x32(IMAGE_NT_HEADERS32)
 * or x64(IMAGE_NT_HEADERS64) structure.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param inhLow  IMAGE_NT_HEADERS32 structure
 * @param inhHigh  IMAGE_NT_HEADERS64 structure
 * 
 * @since 1.0.8
 */
typedef union _UNIVERSAL_IMAGE_HEADER{
    IMAGE_NT_HEADERS32 inhLow;
    IMAGE_NT_HEADERS64 inhHigh;
} UNIVERSAL_IMAGE_HEADER;
