#include "winexe_functions.h"








void PrintDOSStubText(IMAGE_DOS_HEADER* idh, char* buffer)
{
    printf("IMAGE_DOS_HEADER stub=");

    for(int counter = 64; counter < idh->e_lfanew; ++counter)
    {
        printf("%c", buffer[counter]);
    }
    printf("\n");
}



void PrintHeadersData(IMAGE_DOS_HEADER* idh, void* inh, char* buffer, int arch)
{
    PrintDOSHeader(idh, buffer);

    PrintDOSStubText(idh, buffer);

    if(arch == IMAGE_PE_TYPE) // x32
    {
        PrintNTHeaderLow((IMAGE_NT_HEADERS32*)inh);
    }
    else if(arch == IMAGE_PEP_TYPE) // x64
    {
        PrintNTHeaderHigh((IMAGE_NT_HEADERS64*)inh);
    }


}



void PrintDOSHeader(IMAGE_DOS_HEADER* idh, char* buffer)
{
    printf("IMAGE_DOS_HEADER::e_magic=%o\n", idh->e_magic);
    printf("IMAGE_DOS_HEADER::e_cblp=%o\n", idh->e_cblp);
    printf("IMAGE_DOS_HEADER::e_cp=%o\n", idh->e_cp);
    printf("IMAGE_DOS_HEADER::e_crlc=%o\n", idh->e_crlc);
    printf("IMAGE_DOS_HEADER::e_cparhdr=%o\n", idh->e_cparhdr);
    printf("IMAGE_DOSC_HEADER::e_minalloc=%o\n", idh->e_minalloc);
    printf("IMAGE_DOS_HEADER::e_maxalloc=%o\n", idh->e_maxalloc);
    printf("IMAGE_DOS_HEADER::e_ss=%o\n", idh->e_ss);
    printf("IMAGE_DOS_HEADER::e_sp=%o\n", idh->e_sp);
    printf("IMAGE_DOS_HEADER::e_csum=%o\n", idh->e_csum);
    printf("IMAGE_DOS_HEADER::e_ip=%o\n", idh->e_ip);
    printf("IMAGE_DOS_HEADER::e_cs=%o\n", idh->e_cs);
    printf("IMAGE_DOS_HEADER::e_lfarlc=%o\n", idh->e_lfarlc);
    printf("IMAGE_DOS_HEADER::e_ovno=%o\n", idh->e_ovno);
    printf("IMAGE_DOS_HEADER::e_res[0]=%o\n", idh->e_res[0]);
    printf("IMAGE_DOS_HEADER::e_res[1]=%o\n", idh->e_res[1]);
    printf("IMAGE_DOS_HEADER::e_res[2]=%o\n", idh->e_res[2]);
    printf("IMAGE_DOS_HEADER::e_res[3]=%o\n", idh->e_res[3]);
    printf("IMAGE_DOS_HEADER::e_oemid=%o\n", idh->e_oemid);
    printf("IMAGE_DOS_HEADER::e_oeminfo=%o\n", idh->e_oeminfo);
    printf("IMAGE_DOS_HEADER::e_res2[0]=%o\n", idh->e_res2[0]);
    printf("IMAGE_DOS_HEADER::e_res2[1]=%o\n", idh->e_res2[1]);
    printf("IMAGE_DOS_HEADER::e_res2[2]=%o\n", idh->e_res2[2]);
    printf("IMAGE_DOS_HEADER::e_res2[3]=%o\n", idh->e_res2[3]);
    printf("IMAGE_DOS_HEADER::e_res2[4]=%o\n", idh->e_res2[4]);
    printf("IMAGE_DOS_HEADER::e_res2[5]=%o\n", idh->e_res2[5]);
    printf("IMAGE_DOS_HEADER::e_res2[6]=%o\n", idh->e_res2[6]);
    printf("IMAGE_DOS_HEADER::e_res2[7]=%o\n", idh->e_res2[7]);
    printf("IMAGE_DOS_HEADER::e_res2[8]=%o\n", idh->e_res2[8]);
    printf("IMAGE_DOS_HEADER::e_res2[9]=%o\n", idh->e_res2[9]);
    printf("IMAGE_DOS_HEADER::e_lfanew=%o\n", idh->e_lfanew);
}



void PrintNTHeaderLow(IMAGE_NT_HEADERS64* inh)
{
    printf("IMAGE_NT_HEADERS64::Signature=%o\n", inh->Signature);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::Machine=%o\n", inh->FileHeader.Machine);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::NumberOfSections=%o\n", inh->FileHeader.NumberOfSections);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::TimeDateStamp=%o\n", inh->FileHeader.TimeDateStamp);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::PointerToSymbolTable=%o\n", inh->FileHeader.PointerToSymbolTable);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::NumberOfSymbols=%o\n", inh->FileHeader.NumberOfSymbols);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::SizeOfOptionalHeader=%o\n", inh->FileHeader.SizeOfOptionalHeader);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::Characteristics=%o\n", inh->FileHeader.Characteristics);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::Magic=%o\n", inh->OptionalHeader.Magic);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorLinkerVersion=%o\n", inh->OptionalHeader.MajorLinkerVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorLinkerVersion=%o\n", inh->OptionalHeader.MinorLinkerVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfCode=%o\n", inh->OptionalHeader.SizeOfCode);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfInitializedData=%o\n", inh->OptionalHeader.SizeOfInitializedData);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfUninitializedData=%o\n", inh->OptionalHeader.SizeOfUninitializedData);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::AddressOfEntryPoint=%o\n", inh->OptionalHeader.AddressOfEntryPoint);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::BaseOfCode=%o\n", inh->OptionalHeader.BaseOfCode);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::ImageBase=%o\n", inh->OptionalHeader.ImageBase);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SectionAlignment=%o\n", inh->OptionalHeader.SectionAlignment);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::FileAlignment=%o\n", inh->OptionalHeader.FileAlignment);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorOperatingSystemVersion=%o\n", inh->OptionalHeader.MajorOperatingSystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorOperatingSystemVersion=%o\n", inh->OptionalHeader.MinorOperatingSystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorImageVersion=%o\n", inh->OptionalHeader.MajorImageVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorImageVersion=%o\n", inh->OptionalHeader.MinorImageVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorSubsystemVersion=%o\n", inh->OptionalHeader.MajorSubsystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorSubsystemVersion=%o\n", inh->OptionalHeader.MinorSubsystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::Win32VersionValue=%o\n", inh->OptionalHeader.Win32VersionValue);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfImage=%o\n", inh->OptionalHeader.SizeOfImage);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfHeaders=%o\n", inh->OptionalHeader.SizeOfHeaders);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::CheckSum=%o\n", inh->OptionalHeader.CheckSum);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::Subsystem=%o\n", inh->OptionalHeader.Subsystem);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::DllCharacteristics=%o\n", inh->OptionalHeader.DllCharacteristics);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfStackReserve=%o\n", inh->OptionalHeader.SizeOfStackReserve);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfStackCommit=%o\n", inh->OptionalHeader.SizeOfStackCommit);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfHeapReserve=%o\n", inh->OptionalHeader.SizeOfHeapReserve);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfHeapCommit=%o\n", inh->OptionalHeader.SizeOfHeapCommit);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::LoaderFlags=%o\n", inh->OptionalHeader.LoaderFlags);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::NumberOfRvaAndSizes=%o\n", inh->OptionalHeader.NumberOfRvaAndSizes);
}



void PrintNTHeaderHigh(IMAGE_NT_HEADERS32* inh)
{
    printf("IMAGE_NT_HEADERS64::Signature=%o\n", inh->Signature);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::Machine=%o\n", inh->FileHeader.Machine);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::NumberOfSections=%o\n", inh->FileHeader.NumberOfSections);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::TimeDateStamp=%o\n", inh->FileHeader.TimeDateStamp);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::PointerToSymbolTable=%o\n", inh->FileHeader.PointerToSymbolTable);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::NumberOfSymbols=%o\n", inh->FileHeader.NumberOfSymbols);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::SizeOfOptionalHeader=%o\n", inh->FileHeader.SizeOfOptionalHeader);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::Characteristics=%o\n", inh->FileHeader.Characteristics);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::Magic=%o\n", inh->OptionalHeader.Magic);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorLinkerVersion=%o\n", inh->OptionalHeader.MajorLinkerVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorLinkerVersion=%o\n", inh->OptionalHeader.MinorLinkerVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfCode=%o\n", inh->OptionalHeader.SizeOfCode);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfInitializedData=%o\n", inh->OptionalHeader.SizeOfInitializedData);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfUninitializedData=%o\n", inh->OptionalHeader.SizeOfUninitializedData);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::AddressOfEntryPoint=%o\n", inh->OptionalHeader.AddressOfEntryPoint);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::BaseOfCode=%o\n", inh->OptionalHeader.BaseOfCode);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::BaseOfData=%o\n", inh->OptionalHeader.BaseOfData);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::ImageBase=%o\n", inh->OptionalHeader.ImageBase);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SectionAlignment=%o\n", inh->OptionalHeader.SectionAlignment);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::FileAlignment=%o\n", inh->OptionalHeader.FileAlignment);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorOperatingSystemVersion=%o\n", inh->OptionalHeader.MajorOperatingSystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorOperatingSystemVersion=%o\n", inh->OptionalHeader.MinorOperatingSystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorImageVersion=%o\n", inh->OptionalHeader.MajorImageVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorImageVersion=%o\n", inh->OptionalHeader.MinorImageVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorSubsystemVersion=%o\n", inh->OptionalHeader.MajorSubsystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorSubsystemVersion=%o\n", inh->OptionalHeader.MinorSubsystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::Win32VersionValue=%o\n", inh->OptionalHeader.Win32VersionValue);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfImage=%o\n", inh->OptionalHeader.SizeOfImage);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfHeaders=%o\n", inh->OptionalHeader.SizeOfHeaders);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::CheckSum=%o\n", inh->OptionalHeader.CheckSum);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::Subsystem=%o\n", inh->OptionalHeader.Subsystem);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::DllCharacteristics=%o\n", inh->OptionalHeader.DllCharacteristics);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfStackReserve=%o\n", inh->OptionalHeader.SizeOfStackReserve);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfStackCommit=%o\n", inh->OptionalHeader.SizeOfStackCommit);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfHeapReserve=%o\n", inh->OptionalHeader.SizeOfHeapReserve);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfHeapCommit=%o\n", inh->OptionalHeader.SizeOfHeapCommit);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::LoaderFlags=%o\n", inh->OptionalHeader.LoaderFlags);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::NumberOfRvaAndSizes=%o\n", inh->OptionalHeader.NumberOfRvaAndSizes);
}



void PrintNTDataDirectoryHeader(IMAGE_DATA_DIRECTORY* idd)
{
    for(int counter = 0; counter < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; ++counter)
    {

    }
}



int DeterminePEFormat(char* buffer)
{
    long offset = MAKELONG(MAKEWORD(buffer[60], buffer[61]), MAKEWORD(buffer[62], buffer[63]));

    if(buffer[offset] == 'P' && buffer[offset + 1] == 'E')
    {
        if(buffer[offset + 2] == '+')
        {
            return IMAGE_PEP_TYPE;
        }
        return IMAGE_PE_TYPE;
    }
    return -1;
}



bool bIsFilePEExecutable(char* buffer)
{
    if(buffer[0] != "4d" || buffer[1] != "5a")
    {
        return false;
    }

    long offset = MAKELONG(MAKEWORD(buffer[60], buffer[61]), MAKEWORD(buffer[62], buffer[63]));

    if(buffer[offset] == 'P' && buffer[offset + 1] == 'E')
    {
        return true;
    }
    return false;
}
