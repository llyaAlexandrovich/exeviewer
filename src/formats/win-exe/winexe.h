#pragma once



#include "../../types.h"



#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16
#define IMAGE_SIZEOF_FILE_HEADER         20



#define IMAGE_PE_TYPE                    0x10b
#define IMAGE_PEP_TYPE                   0x20b



// Available machine types.
#define IMAGE_FILE_MACHINE_UNKNOWN           0
#define IMAGE_FILE_MACHINE_I386              0x014c  // Intel 386 or later processors and compatible processors.
#define IMAGE_FILE_MACHINE_R3000BE           0x160   // MIPS x32 big-endian.
#define IMAGE_FILE_MACHINE_R3000             0x0162  // MIPS x32 little-endian.
#define IMAGE_FILE_MACHINE_R4000             0x0166  // MIPS x32 little-endian.
#define IMAGE_FILE_MACHINE_R10000            0x0168  // MIPS x32 little-endian.
#define IMAGE_FILE_MACHINE_WCEMIPSV2         0x0169  // MIPS little-endian WCE v2.
#define IMAGE_FILE_MACHINE_ALPHA             0x0184  // Alpha_AXP x32.
#define IMAGE_FILE_MACHINE_SH3               0x01a2  // Hitachi SH3 little-endian.
#define IMAGE_FILE_MACHINE_SH3DSP            0x01a3  // Hitachi SH3 DSP.
#define IMAGE_FILE_MACHINE_SH3E              0x01a4  // SH3E little-endian.
#define IMAGE_FILE_MACHINE_SH4               0x01a6  // Hitachi SH4 little-endian.
#define IMAGE_FILE_MACHINE_SH5               0x01a8  // Hitachi SH5.
#define IMAGE_FILE_MACHINE_ARM               0x01c0  // ARM little-endian.
#define IMAGE_FILE_MACHINE_THUMB             0x01c2  // ARM Thumb/Thumb-2 Little-Endian.
#define IMAGE_FILE_MACHINE_ARMNT             0x01c4  // ARM Thumb-2 Little-Endian.
#define IMAGE_FILE_MACHINE_AM33              0x01d3  // Matsushita AM33.
#define IMAGE_FILE_MACHINE_POWERPC           0x01F0  // IBM PowerPC little-endian.
#define IMAGE_FILE_MACHINE_POWERPCFP         0x01f1  // Power PC with floating point support.
#define IMAGE_FILE_MACHINE_IA64              0x0200  // Intel Itanium processor family.
#define IMAGE_FILE_MACHINE_MIPS16            0x0266  // MIPS.
#define IMAGE_FILE_MACHINE_ALPHA64           0x0284  // ALPHA x64.
#define IMAGE_FILE_MACHINE_MIPSFPU           0x0366  // MIPS with FPU.
#define IMAGE_FILE_MACHINE_MIPSFPU16         0x0466  // MIPS16 with FPU.
#define IMAGE_FILE_MACHINE_AXP64             IMAGE_FILE_MACHINE_ALPHA64 // AXP 64 (Same as Alpha 64).
#define IMAGE_FILE_MACHINE_EBC               0x0EBC  // EFI Byte Code.
#define IMAGE_FILE_MACHINE_AMD64             0x8664  // AMD x64.
#define IMAGE_FILE_MACHINE_M32R              0x9041  // Mitsubishi M32R little endian.
#define IMAGE_FILE_MACHINE_ARM64             0xAA64  // ARM64 little-endian.



// Characteristics.
#define IMAGE_FILE_RELOCS_STRIPPED           0x0001  // Relocation info stripped from file.
#define IMAGE_FILE_EXECUTABLE_IMAGE          0x0002  // File is executable.
#define IMAGE_FILE_LINE_NUMS_STRIPPED        0x0004  // Line nunbers stripped from file.
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED       0x0008  // Local symbols stripped from file.
#define IMAGE_FILE_AGGRESIVE_WS_TRIM         0x0010  // Aggressively trim working set.
#define IMAGE_FILE_LARGE_ADDRESS_AWARE       0x0020  // App can handle 2gb+ addresses.
#define IMAGE_FILE_BYTES_REVERSED_LO         0x0080  // Bytes of machine word are reversed.
#define IMAGE_FILE_32BIT_MACHINE             0x0100  // 32 bit word machine.
#define IMAGE_FILE_DEBUG_STRIPPED            0x0200  // Debugging info stripped from file in .DBG file.
#define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP   0x0400  // If Image is on removable media, copy and run from the swap file.
#define IMAGE_FILE_NET_RUN_FROM_SWAP         0x0800  // If Image is on Net, copy and run from the swap file.
#define IMAGE_FILE_SYSTEM                    0x1000  // System File.
#define IMAGE_FILE_DLL                       0x2000  // File is a DLL.
#define IMAGE_FILE_UP_SYSTEM_ONLY            0x4000  // File should only be run on a UP machine.
#define IMAGE_FILE_BYTES_REVERSED_HI         0x8000  // Bytes of machine word are reversed.



// DLL characteristics.
//      IMAGE_LIBRARY_PROCESS_INIT                      0x0001  // Reserved.
//      IMAGE_LIBRARY_PROCESS_TERM                      0x0002  // Reserved.
//      IMAGE_LIBRARY_THREAD_INIT                       0x0004  // Reserved.
//      IMAGE_LIBRARY_THREAD_TERM                       0x0008  // Reserved.
#define IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA        0x0020  // Image can handle a high entropy 64-bit virtual address space.
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE           0x0040  // DLL can be relocated at load time.
#define IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY        0x0080  // Code Integrity checks are enforced.
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT              0x0100  // Image is NX compatible.
#define IMAGE_DLLCHARACTERISTICS_NO_ISOLATION           0x0200  // Image understands isolation and doesn't want it
#define IMAGE_DLLCHARACTERISTICS_NO_SEH                 0x0400  // Image does not use SEH. No SE handler may reside in this image.
#define IMAGE_DLLCHARACTERISTICS_NO_BIND                0x0800  // Do not bind this image.
#define IMAGE_DLLCHARACTERISTICS_APPCONTAINER           0x1000  // Image should execute in an AppContainer.
#define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER             0x2000  // A WDM driver.
#define IMAGE_DLLCHARACTERISTICS_GUARD_CF               0x4000  // Image supports Control Flow Guard.
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE  0x8000  // Terminal Server aware.



// Subsystem.
#define IMAGE_SUBSYSTEM_UNKNOWN              0   // An unknown subsystem.
#define IMAGE_SUBSYSTEM_NATIVE               1   // Device drivers and native Windows processes.
#define IMAGE_SUBSYSTEM_WINDOWS_GUI          2   // The Windows graphical user interface (GUI) subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_CUI          3   // The Windows character subsystem.
#define IMAGE_SUBSYSTEM_OS2_CUI              5   // The OS/2 character subsystem.
#define IMAGE_SUBSYSTEM_POSIX_CUI            7   // The Posix character subsystem.
#define IMAGE_SUBSYSTEM_NATIVE_WINDOWS       8   // Native Win9x driver.
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI       9   // Windows CE.
#define IMAGE_SUBSYSTEM_EFI_APPLICATION      10  // An Extensible Firmware Interface (EFI) application.
#define IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  11   // An EFI driver with boot services.
#define IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER   12  // An EFI driver with run-time services.
#define IMAGE_SUBSYSTEM_EFI_ROM              13  // An EFI ROM image
#define IMAGE_SUBSYSTEM_XBOX                 14  // XBOX
#define IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION 16   // Windows boot application.



/**
 * DOS header structure.
 * 
 * @param e_magic  magic number
 * @param e_cblp  bytes on last page of file.
 * @param e_cp  pages in file.
 * @param e_crlc  relocations.
 * @param e_cparhdr  size of header in paragraphs.
 * @param e_minalloc  minimum extra paragraphs needed.
 * @param e_maxalloc  maximum extra paragraphs needed.
 * @param e_ss  initial SS value.
 * @param e_sp  initial SP value.
 * @param e_csum  checksum.
 * @param e_ip  initial IP value.
 * @param e_cs  initial CS value.
 * @param e_lfarlc  file address of relocation table.
 * @param e_ovno  overlay number.
 * @param e_res  reserver.
 * @param e_eomid  OEM identifier.
 * @param e_oeminfo  OEM information.
 * @param e_res2  reserved.
 * @param e_lfanew  file address of new exe header.
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
 * Internal PE header structure.
 * 
 * @param Machine  machine type.
 * @param NumberOfSections  the number of sections.
 * @param TimeDateStamp  the low 32 bits of the number of seconds since epoch.
 * @param PointerToSymbolTable  the file offset of the COFF symbol table.
 * @param NumberOfSymbols  the number of entries in the symbol table.
 * @param SizeOfOptionalHeader  the size of the optional header.
 * @param Characteristics  the flags that indicate the attributes of the file.
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
 * Additional PE+ header structure.
 * 
 * @param Magic  identifies the state of the image file. PE or PE+.
 * @param MajorLinkerVersion  the linker major version number.
 * @param MinorLinkerVersion  the linker minor version number.
 * @param SizeOfCode  the size of the .text section.
 * @param SizeOfInitializedData  the size of the initialized data section
 * @param SizeOfUninitializedData  the size of the .bss section.
 * @param AddressOfEntryPoint  the address of the entry address.
 * @param BaseOfCode  the address of the beginning-of-code section.
 * @param ImageBase  the preferred address when loaded into memory.
 * @param SectionAlignment  the alignment that is used when in loaded into memory.
 * @param FileAlignment  raw alignment that is used to align raw data sections.
 * @param MajorOperatingSystemVersion  the major version number of the required operating system.
 * @param MinorOperatingSystemVersion  the minor version number of the required operating system.
 * @param MajorImageVersion  the major version number of the image.
 * @param MinorImageVersion  the minor version number of the image.
 * @param MajorSubsystemVersion  the major version number of the subsystem.
 * @param MinorSubsystemVersion  the minor version number of the subsystem.
 * @param Win32VersionValue  reserved.
 * @param SizeOfImage  the size of the image in bytes.
 * @param SizeOfHeaders  the size of the DOS and PE headers combined.
 * @param CheckSum  image file checksum.
 * @param Subsystem  the subsystem that is required to run this image.
 * @param DllCharacteristics  Dll characteristics.
 * @param SizeOfStackReserve  the size of the stack to reserve.
 * @param SizeOfStackCommit  the size of the stack to commit.
 * @param SizeOfHeapReserve  the size of the local heap space to reserve.
 * @param SizeOfHeapCommit  the size of the local heap space to commit.
 * @param LoaderFlags  reserved.
 * @param NumberOfRvaAndSizes  the number of data-directory entries in the remainder of the optional header.
 * @param DataDirectory  DataDirectory structure.
 * 
 * @since 1.0.0
 * 
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
 * Additional PE header structure.
 * 
 * @param Magic  identifies the state of the image file. PE or PE+.
 * @param MajorLinkerVersion  the linker major version number.
 * @param MinorLinkerVersion  the linker minor version number.
 * @param SizeOfCode  the size of the .text section.
 * @param SizeOfInitializedData  the size of the initialized data section
 * @param SizeOfUninitializedData  the size of the .bss section.
 * @param AddressOfEntryPoint  the address of the entry address.
 * @param BaseOfCode  the address of the beginning-of-code section.
 * @param ImageBase  the preferred address when loaded into memory.
 * @param SectionAlignment  the alignment that is used when in loaded into memory.
 * @param FileAlignment  raw alignment that is used to align raw data sections.
 * @param MajorOperatingSystemVersion  the major version number of the required operating system.
 * @param MinorOperatingSystemVersion  the minor version number of the required operating system.
 * @param MajorImageVersion  the major version number of the image.
 * @param MinorImageVersion  the minor version number of the image.
 * @param MajorSubsystemVersion  the major version number of the subsystem.
 * @param MinorSubsystemVersion  the minor version number of the subsystem.
 * @param Win32VersionValue  reserved.
 * @param SizeOfImage  the size of the image in bytes.
 * @param SizeOfHeaders  the size of the DOS and PE headers combined.
 * @param CheckSum  image file checksum.
 * @param Subsystem  the subsystem that is required to run this image.
 * @param DllCharacteristics  Dll characteristics.
 * @param SizeOfStackReserve  the size of the stack to reserve.
 * @param SizeOfStackCommit  the size of the stack to commit.
 * @param SizeOfHeapReserve  the size of the local heap space to reserve.
 * @param SizeOfHeapCommit  the size of the local heap space to commit.
 * @param LoaderFlags  reserved.
 * @param NumberOfRvaAndSizes  the number of data-directory entries in the remainder of the optional header.
 * @param DataDirectory  DataDirectory structure.
 * 
 * @since 1.0.0
 * 
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
 * Data Directory structure.
 * 
 * @param VirtualAddress  the address of the table relative to the base 
 * address of the image when the table is loaded.
 * @param Size  size in bytes.
 * 
 * @since 1.0.0
 */
typedef struct _IMAGE_DATA_DIRECTORY
{
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;



/**
 * PE header structure.
 * 
 * @param Signature  a 4-byte signature identifying the file as a PE image.
 * @param FileHeader  an IMAGE_FILE_HEADER structure.
 * @param OptionalHeader  an IMAGE_OPTIONAL_HEADER structure.
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
 * @param Signature  a 4-byte signature identifying the file as a PE image.
 * @param FileHeader  an IMAGE_FILE_HEADER structure.
 * @param OptionalHeader  an IMAGE_OPTIONAL_HEADER structure.
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
 * Fill out IMAGE_DOS_HEADER from given char buffer.
 * 
 * @author  Ilya Alexandrovich
 * 
 * @param idh  pointer to IMAGE_DOS_HEADER structure to write 
 * data In.
 * @param buffer  file buffer.
 * 
 * @since  1.0.0
 */
void FillOutDOSHeader(IMAGE_DOS_HEADER* idh, char* buffer);