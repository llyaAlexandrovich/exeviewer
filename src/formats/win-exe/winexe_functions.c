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



void PrintHeadersDataLow(IMAGE_DOS_HEADER* idh, IMAGE_NT_HEADERS32* inh, char* buffer)
{
    PrintDOSHeader(idh);

    PrintDOSStubText(idh, buffer);

    PrintNTHeaderLow(inh);
}



void PrintHeadersDataHigh(IMAGE_DOS_HEADER* idh, IMAGE_NT_HEADERS64* inh, char* buffer)
{
    PrintDOSHeader(idh);

    PrintDOSStubText(idh, buffer);

    PrintNTHeaderHigh(inh);
}



void PrintDOSHeader(IMAGE_DOS_HEADER* idh)
{
    printf("IMAGE_DOS_HEADER::e_magic=0x%x\n", idh->e_magic);
    printf("IMAGE_DOS_HEADER::e_cblp=0x%x\n", idh->e_cblp);
    printf("IMAGE_DOS_HEADER::e_cp=0x%x\n", idh->e_cp);
    printf("IMAGE_DOS_HEADER::e_crlc=0x%x\n", idh->e_crlc);
    printf("IMAGE_DOS_HEADER::e_cparhdr=0x%x\n", idh->e_cparhdr);
    printf("IMAGE_DOSC_HEADER::e_minalloc=0x%x\n", idh->e_minalloc);
    printf("IMAGE_DOS_HEADER::e_maxalloc=0x%x\n", idh->e_maxalloc);
    printf("IMAGE_DOS_HEADER::e_ss=0x%x\n", idh->e_ss);
    printf("IMAGE_DOS_HEADER::e_sp=0x%x\n", idh->e_sp);
    printf("IMAGE_DOS_HEADER::e_csum=0x%x\n", idh->e_csum);
    printf("IMAGE_DOS_HEADER::e_ip=0x%x\n", idh->e_ip);
    printf("IMAGE_DOS_HEADER::e_cs=0x%x\n", idh->e_cs);
    printf("IMAGE_DOS_HEADER::e_lfarlc=0x%x\n", idh->e_lfarlc);
    printf("IMAGE_DOS_HEADER::e_ovno=0x%x\n", idh->e_ovno);
    printf("IMAGE_DOS_HEADER::e_res[0]=0x%x\n", idh->e_res[0]);
    printf("IMAGE_DOS_HEADER::e_res[1]=0x%x\n", idh->e_res[1]);
    printf("IMAGE_DOS_HEADER::e_res[2]=0x%x\n", idh->e_res[2]);
    printf("IMAGE_DOS_HEADER::e_res[3]=0x%x\n", idh->e_res[3]);
    printf("IMAGE_DOS_HEADER::e_oemid=0x%x\n", idh->e_oemid);
    printf("IMAGE_DOS_HEADER::e_oeminfo=0x%x\n", idh->e_oeminfo);
    printf("IMAGE_DOS_HEADER::e_res2[0]=0x%x\n", idh->e_res2[0]);
    printf("IMAGE_DOS_HEADER::e_res2[1]=0x%x\n", idh->e_res2[1]);
    printf("IMAGE_DOS_HEADER::e_res2[2]=0x%x\n", idh->e_res2[2]);
    printf("IMAGE_DOS_HEADER::e_res2[3]=0x%x\n", idh->e_res2[3]);
    printf("IMAGE_DOS_HEADER::e_res2[4]=0x%x\n", idh->e_res2[4]);
    printf("IMAGE_DOS_HEADER::e_res2[5]=0x%x\n", idh->e_res2[5]);
    printf("IMAGE_DOS_HEADER::e_res2[6]=0x%x\n", idh->e_res2[6]);
    printf("IMAGE_DOS_HEADER::e_res2[7]=0x%x\n", idh->e_res2[7]);
    printf("IMAGE_DOS_HEADER::e_res2[8]=0x%x\n", idh->e_res2[8]);
    printf("IMAGE_DOS_HEADER::e_res2[9]=0x%x\n", idh->e_res2[9]);
    printf("IMAGE_DOS_HEADER::e_lfanew=0x%lx\n", idh->e_lfanew);
}



void PrintNTHeaderLow(IMAGE_NT_HEADERS32* inh)
{
    printf("IMAGE_NT_HEADERS32::Signature=0x%lx\n", inh->Signature);
    printf("IMAGE_NT_HEADERS32::IMAGE_FILE_HADER::Machine=0x%x\n", inh->FileHeader.Machine);
    printf("IMAGE_NT_HEADERS32::IMAGE_FILE_HADER::NumberOfSections=0x%x\n", inh->FileHeader.NumberOfSections);
    printf("IMAGE_NT_HEADERS32::IMAGE_FILE_HADER::TimeDateStamp=0x%lx\n", inh->FileHeader.TimeDateStamp);
    printf("IMAGE_NT_HEADERS32::IMAGE_FILE_HADER::PointerToSymbolTable=0x%lx\n", inh->FileHeader.PointerToSymbolTable);
    printf("IMAGE_NT_HEADERS32::IMAGE_FILE_HADER::NumberOfSymbols=0x%lx\n", inh->FileHeader.NumberOfSymbols);
    printf("IMAGE_NT_HEADERS32::IMAGE_FILE_HADER::SizeOfOptionalHeader=0x%x\n", inh->FileHeader.SizeOfOptionalHeader);
    printf("IMAGE_NT_HEADERS32::IMAGE_FILE_HADER::Characteristics=0x%x\n", inh->FileHeader.Characteristics);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::Magic=0x%x\n", inh->OptionalHeader.Magic);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::MajorLinkerVersion=0x%x\n", inh->OptionalHeader.MajorLinkerVersion);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::MinorLinkerVersion=0x%x\n", inh->OptionalHeader.MinorLinkerVersion);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::SizeOfCode=0x%lx\n", inh->OptionalHeader.SizeOfCode);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::SizeOfInitializedData=0x%lx\n", inh->OptionalHeader.SizeOfInitializedData);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::SizeOfUninitializedData=0x%lx\n", inh->OptionalHeader.SizeOfUninitializedData);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::AddressOfEntryPoint=0x%lx\n", inh->OptionalHeader.AddressOfEntryPoint);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::BaseOfCode=0x%lx\n", inh->OptionalHeader.BaseOfCode);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::BaseOfData=0x%lx\n", inh->OptionalHeader.BaseOfData);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::ImageBase=0x%lx\n", inh->OptionalHeader.ImageBase);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::SectionAlignment=0x%lx\n", inh->OptionalHeader.SectionAlignment);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::FileAlignment=0x%lx\n", inh->OptionalHeader.FileAlignment);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::MajorOperatingSystemVersion=0x%x\n", inh->OptionalHeader.MajorOperatingSystemVersion);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::MinorOperatingSystemVersion=0x%x\n", inh->OptionalHeader.MinorOperatingSystemVersion);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::MajorImageVersion=0x%x\n", inh->OptionalHeader.MajorImageVersion);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::MinorImageVersion=0x%x\n", inh->OptionalHeader.MinorImageVersion);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::MajorSubsystemVersion=0x%x\n", inh->OptionalHeader.MajorSubsystemVersion);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::MinorSubsystemVersion=0x%x\n", inh->OptionalHeader.MinorSubsystemVersion);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::Win32VersionValue=0x%lx\n", inh->OptionalHeader.Win32VersionValue);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::SizeOfImage=0x%lx\n", inh->OptionalHeader.SizeOfImage);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::SizeOfHeaders=0x%lx\n", inh->OptionalHeader.SizeOfHeaders);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::CheckSum=0x%lx\n", inh->OptionalHeader.CheckSum);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::Subsystem=0x%x\n", inh->OptionalHeader.Subsystem);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::DllCharacteristics=0x%x\n", inh->OptionalHeader.DllCharacteristics);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::SizeOfStackReserve=0x%lx\n", inh->OptionalHeader.SizeOfStackReserve);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::SizeOfStackCommit=0x%lx\n", inh->OptionalHeader.SizeOfStackCommit);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::SizeOfHeapReserve=0x%lx\n", inh->OptionalHeader.SizeOfHeapReserve);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::SizeOfHeapCommit=0x%lx\n", inh->OptionalHeader.SizeOfHeapCommit);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::LoaderFlags=0x%lx\n", inh->OptionalHeader.LoaderFlags);
    printf("IMAGE_NT_HEADERS32::IMAGE_OPTIONAL_HEADER32::NumberOfRvaAndSizes=0x%lx\n", inh->OptionalHeader.NumberOfRvaAndSizes);
}



void PrintNTHeaderHigh(IMAGE_NT_HEADERS64* inh)
{
    printf("IMAGE_NT_HEADERS64::Signature=0x%lx\n", inh->Signature);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::Machine=0x%x\n", inh->FileHeader.Machine);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::NumberOfSections=0x%x\n", inh->FileHeader.NumberOfSections);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::TimeDateStamp=0x%lx\n", inh->FileHeader.TimeDateStamp);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::PointerToSymbolTable=0x%lx\n", inh->FileHeader.PointerToSymbolTable);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::NumberOfSymbols=0x%lx\n", inh->FileHeader.NumberOfSymbols);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::SizeOfOptionalHeader=0x%x\n", inh->FileHeader.SizeOfOptionalHeader);
    printf("IMAGE_NT_HEADERS64::IMAGE_FILE_HADER::Characteristics=0x%x\n", inh->FileHeader.Characteristics);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::Magic=0x%x\n", inh->OptionalHeader.Magic);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorLinkerVersion=0x%x\n", inh->OptionalHeader.MajorLinkerVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorLinkerVersion=0x%x\n", inh->OptionalHeader.MinorLinkerVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfCode=0x%lx\n", inh->OptionalHeader.SizeOfCode);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfInitializedData=0x%lx\n", inh->OptionalHeader.SizeOfInitializedData);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfUninitializedData=0x%lx\n", inh->OptionalHeader.SizeOfUninitializedData);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::AddressOfEntryPoint=0x%lx\n", inh->OptionalHeader.AddressOfEntryPoint);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::BaseOfCode=0x%lx\n", inh->OptionalHeader.BaseOfCode);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::ImageBase=0x%llx\n", inh->OptionalHeader.ImageBase);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SectionAlignment=0x%lx\n", inh->OptionalHeader.SectionAlignment);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::FileAlignment=0x%lx\n", inh->OptionalHeader.FileAlignment);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorOperatingSystemVersion=0x%x\n", inh->OptionalHeader.MajorOperatingSystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorOperatingSystemVersion=0x%x\n", inh->OptionalHeader.MinorOperatingSystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorImageVersion=0x%x\n", inh->OptionalHeader.MajorImageVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorImageVersion=0x%x\n", inh->OptionalHeader.MinorImageVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MajorSubsystemVersion=0x%x\n", inh->OptionalHeader.MajorSubsystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::MinorSubsystemVersion=0x%x\n", inh->OptionalHeader.MinorSubsystemVersion);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::Win32VersionValue=0x%lx\n", inh->OptionalHeader.Win32VersionValue);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfImage=0x%lx\n", inh->OptionalHeader.SizeOfImage);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfHeaders=0x%lx\n", inh->OptionalHeader.SizeOfHeaders);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::CheckSum=0x%lx\n", inh->OptionalHeader.CheckSum);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::Subsystem=0x%x\n", inh->OptionalHeader.Subsystem);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::DllCharacteristics=0x%x\n", inh->OptionalHeader.DllCharacteristics);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfStackReserve=0x%llx\n", inh->OptionalHeader.SizeOfStackReserve);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfStackCommit=0x%llx\n", inh->OptionalHeader.SizeOfStackCommit);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfHeapReserve=0x%llx\n", inh->OptionalHeader.SizeOfHeapReserve);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::SizeOfHeapCommit=0x%llx\n", inh->OptionalHeader.SizeOfHeapCommit);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::LoaderFlags=0x%lx\n", inh->OptionalHeader.LoaderFlags);
    printf("IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::NumberOfRvaAndSizes=0x%lx\n", inh->OptionalHeader.NumberOfRvaAndSizes);
}



// void PrintNTDataDirectoryHeader(IMAGE_DATA_DIRECTORY* idd)
// {
//     for(int counter = 0; counter < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; ++counter)
//     {
// 
//     }
// }



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
    if(buffer[0] == 'M' && buffer[1] == 'Z')
    {
        return true;
    }
    return false;
}
