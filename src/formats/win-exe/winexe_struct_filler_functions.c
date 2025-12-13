#include "winexe_struct_filler_functions.h"








void FillOutNTEntireStructure(IMAGE_DOS_HEADER* idh, void* inh, char* buffer, int arch)
{
    FillOutDOSHeader(idh, buffer); // Fill out IMAGE_DOS_HEADER structure.

    // Fill out IMAGE_NT_HEADERS32 or IMAGE_NT_HEADERS64 structure
    FillOutNTHeader(idh, buffer, inh, arch);
}



void FillOutDOSHeader(IMAGE_DOS_HEADER* idh, char* buffer)
{
    idh->e_magic    = MAKEWORD(buffer[0], buffer[1]);
    idh->e_cblp     = MAKEWORD(buffer[2], buffer[3]);
    idh->e_cp       = MAKEWORD(buffer[4], buffer[5]);
    idh->e_crlc     = MAKEWORD(buffer[6], buffer[7]);
    idh->e_cparhdr  = MAKEWORD(buffer[8], buffer[9]);
    idh->e_minalloc = MAKEWORD(buffer[10], buffer[11]);
    idh->e_maxalloc = MAKEWORD(buffer[12], buffer[13]);
    idh->e_ss       = MAKEWORD(buffer[14], buffer[15]);
    idh->e_sp       = MAKEWORD(buffer[16], buffer[17]);
    idh->e_csum     = MAKEWORD(buffer[18], buffer[19]);
    idh->e_ip       = MAKEWORD(buffer[20], buffer[21]);
    idh->e_cs       = MAKEWORD(buffer[22], buffer[23]);
    idh->e_lfarlc   = MAKEWORD(buffer[24], buffer[25]);
    idh->e_ovno     = MAKEWORD(buffer[26], buffer[27]);
    idh->e_res[0]   = MAKEWORD(buffer[28], buffer[29]);
    idh->e_res[1]   = MAKEWORD(buffer[30], buffer[31]);
    idh->e_res[2]   = MAKEWORD(buffer[32], buffer[33]);
    idh->e_res[3]   = MAKEWORD(buffer[34], buffer[35]);
    idh->e_oemid    = MAKEWORD(buffer[36], buffer[37]);
    idh->e_oeminfo  = MAKEWORD(buffer[38], buffer[39]);
    idh->e_res2[0]  = MAKEWORD(buffer[40], buffer[41]);
    idh->e_res2[1]  = MAKEWORD(buffer[42], buffer[43]);
    idh->e_res2[2]  = MAKEWORD(buffer[44], buffer[45]);
    idh->e_res2[3]  = MAKEWORD(buffer[46], buffer[47]);
    idh->e_res2[4]  = MAKEWORD(buffer[48], buffer[49]);
    idh->e_res2[5]  = MAKEWORD(buffer[50], buffer[51]);
    idh->e_res2[6]  = MAKEWORD(buffer[52], buffer[53]);
    idh->e_res2[7]  = MAKEWORD(buffer[54], buffer[55]);
    idh->e_res2[8]  = MAKEWORD(buffer[56], buffer[57]);
    idh->e_res2[9]  = MAKEWORD(buffer[58], buffer[59]);
    idh->e_lfanew   = MAKELONG(MAKEWORD(buffer[60], buffer[61]), MAKEWORD(buffer[62], buffer[63]));
}



void FillOutNTHeader(IMAGE_DOS_HEADER* idh, char* buffer, void* inh, int arch)
{
    long offset = idh->e_lfanew;

    if(arch == IMAGE_PE_TYPE) // x32
    {
        ((IMAGE_NT_HEADERS32*)inh)->Signature = \
        MAKELONG(MAKEWORD(buffer[offset], buffer[offset + 1]), MAKEWORD(buffer[offset + 2], buffer[offset + 3]));

        FillOutNTFileHeader(idh, buffer, &(IMAGE_FILE_HEADER)((IMAGE_NT_HEADERS32*)inh)->FileHeader);

        FillOutNTOptionalHeaderLow(idh, buffer, &(IMAGE_OPTIONAL_HEADER32)((IMAGE_NT_HEADERS32*)inh)->OptionalHeader);

        FillOutNTDataDirectoryHeader(idh, buffer, (IMAGE_DATA_DIRECTORY*)((IMAGE_NT_HEADERS32*)inh)->OptionalHeader.DataDirectory);
    }
    else if(arch == IMAGE_PEP_TYPE) // x64
    {
        ((IMAGE_NT_HEADERS64*)inh)->Signature = \
        MAKELONG(MAKEWORD(buffer[offset], buffer[offset + 1]), MAKEWORD(buffer[offset + 2], buffer[offset + 3]));

        FillOutNTFileHeader(idh, buffer, &(IMAGE_FILE_HEADER)((IMAGE_NT_HEADERS64*)inh)->FileHeader);

        FillOutNTOptionalHeaderHigh(idh, buffer, &(IMAGE_OPTIONAL_HEADER64)((IMAGE_NT_HEADERS64*)inh)->OptionalHeader);

        FillOutNTDataDirectoryHeader(idh, buffer, (IMAGE_DATA_DIRECTORY*)((IMAGE_NT_HEADERS64*)inh)->OptionalHeader.DataDirectory);
    }  
}



void FillOutNTFileHeader(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_FILE_HEADER* ifh)
{
    long offset = idh->e_lfanew + 4; // Offset + PE magic 4 bytes.

    ifh->Machine = MAKEWORD(buffer[offset], buffer[offset + 1]);
    ifh->NumberOfSections = MAKEWORD(buffer[offset + 2], buffer[offset + 3]);
    ifh->TimeDateStamp = \
    MAKELONG(MAKEWORD(buffer[offset + 4], buffer[offset + 5]), MAKEWORD(buffer[offset + 6], buffer[offset + 7]));
    ifh->PointerToSymbolTable = \
    MAKELONG(MAKEWORD(buffer[offset + 8], buffer[offset + 9]), MAKEWORD(buffer[offset + 10], buffer[offset + 11]));
    ifh->NumberOfSymbols = \
    MAKELONG(MAKEWORD(buffer[offset + 12], buffer[offset + 13]), MAKEWORD(buffer[offset + 14], buffer[offset + 15]));
    ifh->SizeOfOptionalHeader = MAKEWORD(buffer[offset + 16], buffer[offset + 17]);
    ifh->Characteristics = MAKEWORD(buffer[offset + 18], buffer[offset + 19]);
}



void FillOutNTOptionalHeaderLow(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_OPTIONAL_HEADER32* ioh)
{
    long offset = idh->e_lfanew + 4 + IMAGE_SIZEOF_FILE_HEADER; // Offset + PE magic 4 bytes + IMAGE_FILE_HEADER size.

    ioh->Magic = MAKEWORD(buffer[offset], buffer[offset + 1]);
    ioh->MajorLinkerVersion = buffer[offset + 2];
    ioh->MinorLinkerVersion = buffer[offset + 3];
    ioh->SizeOfCode = \
    MAKELONG(MAKEWORD(buffer[offset + 4], buffer[offset + 5]), MAKEWORD(buffer[offset + 6], buffer[offset + 7]));
    ioh->SizeOfInitializedData = \
    MAKELONG(MAKEWORD(buffer[offset + 8], buffer[offset + 9]), MAKEWORD(buffer[offset + 10], buffer[offset + 11]));
    ioh->SizeOfUninitializedData = \
    MAKELONG(MAKEWORD(buffer[offset + 12], buffer[offset + 13]), MAKEWORD(buffer[offset + 14], buffer[offset + 15]));
    ioh->AddressOfEntryPoint = \
    MAKELONG(MAKEWORD(buffer[offset + 16], buffer[offset + 17]), MAKEWORD(buffer[offset + 18], buffer[offset + 19]));
    ioh->BaseOfCode = \
    MAKELONG(MAKEWORD(buffer[offset + 20], buffer[offset + 21]), MAKEWORD(buffer[offset + 22], buffer[offset + 23]));
    ioh->BaseOfData = \
    MAKELONG(MAKEWORD(buffer[offset + 24], buffer[offset + 25]), MAKEWORD(buffer[offset + 26], buffer[offset + 27]));
    ioh->ImageBase = \
    MAKELONG(MAKEWORD(buffer[offset + 28], buffer[offset + 29]), MAKEWORD(buffer[offset + 30], buffer[offset + 31]));
    ioh->SectionAlignment = \
    MAKELONG(MAKEWORD(buffer[offset + 32], buffer[offset + 33]), MAKEWORD(buffer[offset + 34], buffer[offset + 35]));
    ioh->FileAlignment = \
    MAKELONG(MAKEWORD(buffer[offset + 36], buffer[offset + 37]), MAKEWORD(buffer[offset + 38], buffer[offset + 39]));
    ioh->MajorOperatingSystemVersion = MAKEWORD(buffer[offset + 40], buffer[offset + 41]);
    ioh->MinorOperatingSystemVersion = MAKEWORD(buffer[offset + 42], buffer[offset + 43]);
    ioh->MajorImageVersion = MAKEWORD(buffer[offset + 44], buffer[offset + 45]);
    ioh->MinorImageVersion = MAKEWORD(buffer[offset + 46], buffer[offset + 47]);
    ioh->MajorSubsystemVersion = MAKEWORD(buffer[offset + 48], buffer[offset + 49]);
    ioh->MinorSubsystemVersion = MAKEWORD(buffer[offset + 50], buffer[offset + 51]);
    ioh->Win32VersionValue = \
    MAKELONG(MAKEWORD(buffer[offset + 52], buffer[offset + 53]), MAKEWORD(buffer[offset + 54], buffer[offset + 55]));
    ioh->SizeOfImage = \
    MAKELONG(MAKEWORD(buffer[offset + 56], buffer[offset + 57]), MAKEWORD(buffer[offset + 58], buffer[offset + 59]));
    ioh->SizeOfHeaders = \
    MAKELONG(MAKEWORD(buffer[offset + 60], buffer[offset + 61]), MAKEWORD(buffer[offset + 62], buffer[offset + 63]));
    ioh->CheckSum = \
    MAKELONG(MAKEWORD(buffer[offset + 64], buffer[offset + 65]), MAKEWORD(buffer[offset + 66], buffer[offset + 67]));
    ioh->Subsystem = MAKEWORD(buffer[offset + 68], buffer[offset + 69]);
    ioh->DllCharacteristics = MAKEWORD(buffer[offset + 70], buffer[offset + 71]);
    ioh->SizeOfStackReserve = \
    MAKELONG(MAKEWORD(buffer[offset + 72], buffer[offset + 73]), MAKEWORD(buffer[offset + 74], buffer[offset + 75]));
    ioh->SizeOfStackCommit = \
    MAKELONG(MAKEWORD(buffer[offset + 76], buffer[offset + 77]), MAKEWORD(buffer[offset + 78], buffer[offset + 79]));
    ioh->SizeOfHeapReserve = \
    MAKELONG(MAKEWORD(buffer[offset + 80], buffer[offset + 81]), MAKEWORD(buffer[offset + 82], buffer[offset + 83]));
    ioh->SizeOfHeapCommit = \
    MAKELONG(MAKEWORD(buffer[offset + 84], buffer[offset + 85]), MAKEWORD(buffer[offset + 86], buffer[offset + 87]));
    ioh->LoaderFlags = \
    MAKELONG(MAKEWORD(buffer[offset + 88], buffer[offset + 89]), MAKEWORD(buffer[offset + 90], buffer[offset + 91]));
    ioh->NumberOfRvaAndSizes = \
    MAKELONG(MAKEWORD(buffer[offset + 92], buffer[offset + 93]), MAKEWORD(buffer[offset + 94], buffer[offset + 95]));
}



void FillOutNTOptionalHeaderHigh(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_OPTIONAL_HEADER64* ioh)
{
    long offset = idh->e_lfanew + 4 + IMAGE_SIZEOF_FILE_HEADER; // Offset + PE magic 4 bytes + IMAGE_FILE_HEADER size.

    ioh->Magic = MAKEWORD(buffer[offset], buffer[offset + 1]);
    ioh->MajorLinkerVersion = buffer[offset + 2];
    ioh->MinorLinkerVersion = buffer[offset + 3];
    ioh->SizeOfCode = \
    MAKELONG(MAKEWORD(buffer[offset + 4], buffer[offset + 5]), MAKEWORD(buffer[offset + 6], buffer[offset + 7]));
    ioh->SizeOfInitializedData = \
    MAKELONG(MAKEWORD(buffer[offset + 8], buffer[offset + 9]), MAKEWORD(buffer[offset + 10], buffer[offset + 11]));
    ioh->SizeOfUninitializedData = \
    MAKELONG(MAKEWORD(buffer[offset + 12], buffer[offset + 13]), MAKEWORD(buffer[offset + 14], buffer[offset + 15]));
    ioh->AddressOfEntryPoint = \
    MAKELONG(MAKEWORD(buffer[offset + 16], buffer[offset + 17]), MAKEWORD(buffer[offset + 18], buffer[offset + 19]));
    ioh->BaseOfCode = \
    MAKELONG(MAKEWORD(buffer[offset + 20], buffer[offset + 21]), MAKEWORD(buffer[offset + 22], buffer[offset + 23]));
    ioh->ImageBase = MAKEULONGLONG(\
    MAKELONG(MAKEWORD(buffer[offset + 24], buffer[offset + 25]), MAKEWORD(buffer[offset + 26], buffer[offset + 27])), \
    MAKELONG(MAKEWORD(buffer[offset + 28], buffer[offset + 29]), MAKEWORD(buffer[offset + 30], buffer[offset + 31])));
    ioh->SectionAlignment = \
    MAKELONG(MAKEWORD(buffer[offset + 32], buffer[offset + 33]), MAKEWORD(buffer[offset + 34], buffer[offset + 35]));
    ioh->FileAlignment = \
    MAKELONG(MAKEWORD(buffer[offset + 36], buffer[offset + 37]), MAKEWORD(buffer[offset + 38], buffer[offset + 39]));
    ioh->MajorOperatingSystemVersion = MAKEWORD(buffer[offset + 40], buffer[offset + 41]);
    ioh->MinorOperatingSystemVersion = MAKEWORD(buffer[offset + 42], buffer[offset + 43]);
    ioh->MajorImageVersion = MAKEWORD(buffer[offset + 44], buffer[offset + 45]);
    ioh->MinorImageVersion = MAKEWORD(buffer[offset + 46], buffer[offset + 47]);
    ioh->MajorSubsystemVersion = MAKEWORD(buffer[offset + 48], buffer[offset + 49]);
    ioh->MinorSubsystemVersion = MAKEWORD(buffer[offset + 50], buffer[offset + 51]);
    ioh->Win32VersionValue = \
    MAKELONG(MAKEWORD(buffer[offset + 52], buffer[offset + 53]), MAKEWORD(buffer[offset + 54], buffer[offset + 55]));
    ioh->SizeOfImage = \
    MAKELONG(MAKEWORD(buffer[offset + 56], buffer[offset + 57]), MAKEWORD(buffer[offset + 58], buffer[offset + 59]));
    ioh->SizeOfHeaders = \
    MAKELONG(MAKEWORD(buffer[offset + 60], buffer[offset + 61]), MAKEWORD(buffer[offset + 62], buffer[offset + 63]));
    ioh->CheckSum = \
    MAKELONG(MAKEWORD(buffer[offset + 64], buffer[offset + 65]), MAKEWORD(buffer[offset + 66], buffer[offset + 67]));
    ioh->Subsystem = MAKEWORD(buffer[offset + 68], buffer[offset + 69]);
    ioh->DllCharacteristics = MAKEWORD(buffer[offset + 70], buffer[offset + 71]);
    ioh->SizeOfStackReserve = MAKEULONGLONG(\
    MAKELONG(MAKEWORD(buffer[offset + 72], buffer[offset + 73]), MAKEWORD(buffer[offset + 74], buffer[offset + 75])), \
    MAKELONG(MAKEWORD(buffer[offset + 76], buffer[offset + 77]), MAKEWORD(buffer[offset + 78], buffer[offset + 79])));
    ioh->SizeOfStackCommit = MAKEULONGLONG(\
    MAKELONG(MAKEWORD(buffer[offset + 80], buffer[offset + 81]), MAKEWORD(buffer[offset + 82], buffer[offset + 83])), \
    MAKELONG(MAKEWORD(buffer[offset + 84], buffer[offset + 85]), MAKEWORD(buffer[offset + 86], buffer[offset + 87])));
    ioh->SizeOfHeapReserve = MAKEULONGLONG(\
    MAKELONG(MAKEWORD(buffer[offset + 88], buffer[offset + 89]), MAKEWORD(buffer[offset + 90], buffer[offset + 91])), \
    MAKELONG(MAKEWORD(buffer[offset + 92], buffer[offset + 93]), MAKEWORD(buffer[offset + 94], buffer[offset + 95])));
    ioh->SizeOfHeapCommit =MAKEULONGLONG(\
    MAKELONG(MAKEWORD(buffer[offset + 96], buffer[offset + 97]), MAKEWORD(buffer[offset + 98], buffer[offset + 99])), \
    MAKELONG(MAKEWORD(buffer[offset + 100], buffer[offset + 101]), MAKEWORD(buffer[offset + 102], buffer[offset + 103])));
    ioh->LoaderFlags = \
    MAKELONG(MAKEWORD(buffer[offset + 104], buffer[offset + 105]), MAKEWORD(buffer[offset + 106], buffer[offset + 107]));
    ioh->NumberOfRvaAndSizes = \
    MAKELONG(MAKEWORD(buffer[offset + 108], buffer[offset + 109]), MAKEWORD(buffer[offset + 110], buffer[offset + 111]));
}



void FillOutNTDataDirectoryHeaderLow(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_DATA_DIRECTORY* idd)
{
    long offset = idh->e_lfanew + 4 + IMAGE_SIZEOF_OPTIONAL_HEADER32; // Offset + PE magic 4 bytes + IMAGE_OPTIONAL_HEADER32 size.

    for(int counter = 0; counter < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; ++counter)
    {
        idd[counter].VirtualAddress = \
        MAKELONG(MAKEWORD(buffer[offset], buffer[offset + 1]), MAKEWORD(buffer[offset + 2], buffer[offset + 3]));
        idd[counter].Size = \
        MAKELONG(MAKEWORD(buffer[offset + 4], buffer[offset + 5]), MAKEWORD(buffer[offset + 6], buffer[offset + 7]));
    }
}



void FillOutNTDataDirectoryHeaderHigh(IMAGE_DOS_HEADER* idh, char* buffer, IMAGE_DATA_DIRECTORY* idd)
{
    long offset = idh->e_lfanew + 4 + IMAGE_SIZEOF_OPTIONAL_HEADER64; // Offset + PE magic 4 bytes + IMAGE_OPTIONAL_HEADER32 size.

    for(int counter = 0; counter < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; ++counter)
    {
        idd[counter].VirtualAddress = \
        MAKELONG(MAKEWORD(buffer[offset], buffer[offset + 1]), MAKEWORD(buffer[offset + 2], buffer[offset + 3]));
        idd[counter].Size = \
        MAKELONG(MAKEWORD(buffer[offset + 4], buffer[offset + 5]), MAKEWORD(buffer[offset + 6], buffer[offset + 7]));
    }
}



void FillOutDataSection(IMAGE_DOS_HEADER* idh, char* buffer, void* inh, int arch, IMAGE_SECTION_HEADER* ish)
{
    if(arch == IMAGE_PE_TYPE) //x32
    {
        // Offset + PE magic 4 bytes + IMAGE_OPTIONAL_HEADER32 size.
        long offset = idh->e_lfanew + 4 + IMAGE_SIZEOF_OPTIONAL_HEADER32;

        
    }
    else if(arch == IMAGE_PEP_TYPE) //x64
    {
        // Offset + PE magic 4 bytes + IMAGE_OPTIONAL_HEADER64 size.
        long offset = idh->e_lfanew + 4 + IMAGE_SIZEOF_OPTIONAL_HEADER32;
    }
}
