#pragma once



#include <iostream>
#include <string>



#include "exe_types.hpp"


namespace ExeViewer
{
    /**
     * DOS header structure. Actually old useless stub.
     * 
     * @param e_magic  magic number
     * @param e_cblp  std::bytes on last page of file
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
    #pragma pack(push, 1)
    struct IMAGE_DOS_HEADER // Real size = 64 bytes
    {
        std::uint16_t   e_magic;
        std::uint16_t   e_cblp;
        std::uint16_t   e_cp;
        std::uint16_t   e_crlc;
        std::uint16_t   e_cparhdr;
        std::uint16_t   e_minalloc;
        std::uint16_t   e_maxalloc;
        std::uint16_t   e_ss;
        std::uint16_t   e_sp;
        std::uint16_t   e_csum;
        std::uint16_t   e_ip;
        std::uint16_t   e_cs;
        std::uint16_t   e_lfarlc;
        std::uint16_t   e_ovno;
        std::uint16_t   e_res[4];
        std::uint16_t   e_oemid;
        std::uint16_t   e_oeminfo;
        std::uint16_t   e_res2[10];
        std::int32_t    e_lfanew;
    };


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
    struct  IMAGE_FILE_HEADER
    {
        std::uint16_t    Machine;
        std::uint16_t    NumberOfSections;
        std::uint32_t    TimeDateStamp;
        std::uint32_t    PointerToSymbolTable;
        std::uint32_t    NumberOfSymbols;
        std::uint16_t    SizeOfOptionalHeader;
        std::uint16_t    Characteristics;
    };
    

    /**
     * Data Directory structure.
     * 
     * @param VirtualAddress  the address of the table relative to the base 
     * address of the image when the table is loaded
     * @param Size  size in std::bytes
     * 
     * @since 1.0.0
     */
    struct IMAGE_DATA_DIRECTORY
    {
        std::uint32_t   VirtualAddress;
        std::uint32_t   Size;
    };


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
    struct IMAGE_SECTION_HEADER
    {
        std::byte    Name[IMAGE_SIZEOF_SHORT_NAME];
        union
        {
                std::uint32_t   PhysicalAddress;
                std::uint32_t   VirtualSize;
        } Misc;
        std::uint32_t   VirtualAddress;
        std::uint32_t   SizeOfRawData;
        std::uint32_t   PointerToRawData;
        std::uint32_t   PointerToRelocations;
        std::uint32_t   PointerToLinenumbers;
        std::uint16_t   NumberOfRelocations;
        std::uint16_t   NumberOfLinenumbers;
        std::uint32_t   Characteristics;
    };


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
     * @param SizeOfImage  the size of the image in std::bytes
     * @param SizeOfHeaders  the size of the DOS and PE headers combined
     * @param CheckSum  image file checksum
     * @param Subsystem  the subsystem that is required to run this image
     * @param DllCharacteristics  Dll Characteristics
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
    struct IMAGE_OPTIONAL_HEADER32
    {
        std::uint16_t   Magic;
        std::byte       MajorLinkerVersion;
        std::byte       MinorLinkerVersion;
        std::uint32_t   SizeOfCode;
        std::uint32_t   SizeOfInitializedData;
        std::uint32_t   SizeOfUninitializedData;
        std::uint32_t   AddressOfEntryPoint;
        std::uint32_t   BaseOfCode;
        std::uint32_t   BaseOfData;
        std::uint32_t   ImageBase;
        std::uint32_t   SectionAlignment;
        std::uint32_t   FileAlignment;
        std::uint16_t   MajorOperatingSystemVersion;
        std::uint16_t   MinorOperatingSystemVersion;
        std::uint16_t   MajorImageVersion;
        std::uint16_t   MinorImageVersion;
        std::uint16_t   MajorSubsystemVersion;
        std::uint16_t   MinorSubsystemVersion;
        std::uint32_t   Win32VersionValue;
        std::uint32_t   SizeOfImage;
        std::uint32_t   SizeOfHeaders;
        std::uint32_t   CheckSum;
        std::uint16_t   Subsystem;
        std::uint16_t   DllCharacteristics;
        std::uint32_t   SizeOfStackReserve;
        std::uint32_t   SizeOfStackCommit;
        std::uint32_t   SizeOfHeapReserve;
        std::uint32_t   SizeOfHeapCommit;
        std::uint32_t   LoaderFlags;
        std::uint32_t   NumberOfRvaAndSizes;
        IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    };


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
     * @param SizeOfImage  the size of the image in std::bytes
     * @param SizeOfHeaders  the size of the DOS and PE headers combined
     * @param CheckSum  image file checksum
     * @param Subsystem  the subsystem that is required to run this image
     * @param DllCharacteristics  Dll Characteristics
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
    struct IMAGE_OPTIONAL_HEADER64
    {
        std::uint16_t       Magic;
        std::byte           MajorLinkerVersion;
        std::byte           MinorLinkerVersion;
        std::uint32_t       SizeOfCode;
        std::uint32_t       SizeOfInitializedData;
        std::uint32_t       SizeOfUninitializedData;
        std::uint32_t       AddressOfEntryPoint;
        std::uint32_t       BaseOfCode;
        std::uint64_t       ImageBase;
        std::uint32_t       SectionAlignment;
        std::uint32_t       FileAlignment;
        std::uint16_t       MajorOperatingSystemVersion;
        std::uint16_t       MinorOperatingSystemVersion;
        std::uint16_t       MajorImageVersion;
        std::uint16_t       MinorImageVersion;
        std::uint16_t       MajorSubsystemVersion;
        std::uint16_t       MinorSubsystemVersion;
        std::uint32_t       Win32VersionValue;
        std::uint32_t       SizeOfImage;
        std::uint32_t       SizeOfHeaders;
        std::uint32_t       CheckSum;
        std::uint16_t       Subsystem;
        std::uint16_t       DllCharacteristics;
        std::uint64_t       SizeOfStackReserve;
        std::uint64_t       SizeOfStackCommit;
        std::uint64_t       SizeOfHeapReserve;
        std::uint64_t       SizeOfHeapCommit;
        std::uint32_t       LoaderFlags;
        std::uint32_t       NumberOfRvaAndSizes;
        IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    };


    /**
     * PE header structure.
     * 
     * @param Signature  a 4-std::byte signature identifying the file as a PE image
     * @param FileHeader  an IMAGE_FILE_HEADER structure
     * @param OptionalHeader  an IMAGE_OPTIONAL_HEADER structure
     * 
     * @since 1.0.0
     */
    struct IMAGE_NT_HEADERS64
    {
        std::uint32_t Signature;
        IMAGE_FILE_HEADER FileHeader;
        IMAGE_OPTIONAL_HEADER64 OptionalHeader;
    };


    /**
     * PE+ header structure.
     * 
     * @param Signature  a 4-std::byte signature identifying the file as a PE image
     * @param FileHeader  an IMAGE_FILE_HEADER structure
     * @param OptionalHeader  an IMAGE_OPTIONAL_HEADER structure
     * 
     * @since 1.0.0
     */
    struct IMAGE_NT_HEADERS32
    {
        std::uint32_t Signature;
        IMAGE_FILE_HEADER FileHeader;
        IMAGE_OPTIONAL_HEADER32 OptionalHeader;
    };


    /**
     * Universal union for containing whether x32(IMAGE_NT_HEADERS32)
     * or x64(IMAGE_NT_HEADERS64) structure.
     * 
     * @author Ilya Alexandrovich
     * 
     * @param inhLow  IMAGE_NT_HEADERS32 structure
     * @param inhHigh  IMAGE_NT_HEADERS64 structure
     * 
     * @since 1.0.0
     */
    union UNIVERSAL_IMAGE_HEADER{
        IMAGE_NT_HEADERS32 inhLow;
        IMAGE_NT_HEADERS64 inhHigh;
    };


    /**
     * Сomprehensive exe structure.
     * 
     * @author Ilya Alexandrovich
     * 
     * @param idh  IMAGE_DOS_HEADER structure
     */
    struct alignas(64) ExeInfo
    {
        IMAGE_DOS_HEADER IDH;
        std::string IDHStub;
        enum TYPE {High = 1, Low = 2} Type;
        UNIVERSAL_IMAGE_HEADER UIH;
    };
    #pragma pack(pop)
};
