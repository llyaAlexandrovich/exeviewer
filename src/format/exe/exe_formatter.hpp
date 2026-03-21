#pragma once



#include <iostream>
#include <string>
#include <string_view>
#include <format>
#include <chrono>


#include "exe_info.hpp"
#include "exe_info.hpp"






// Determine IMAGE_NT_HEADERS::IMAGE_FILE_HEADER::MACHINE type.
#define DETERMINE_MACHINE(x) std::string(x == IMAGE_FILE_MACHINE_UNKNOWN ? "MACHINE_UNKNOWN" : x == IMAGE_FILE_MACHINE_I386 ? "MACHINE_I386"\
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


// Determine IMAGE_NT_HEADERS64::IMAGE_OPTIONAL_HEADER64::Subsystem type.
#define DETERMINE_SUBSYSTEM(x) std::string(x == IMAGE_SUBSYSTEM_UNKNOWN ? "" : x == IMAGE_SUBSYSTEM_NATIVE ? "IMAGE_SUBSYSTEM_NATIVE"\
 : x == IMAGE_SUBSYSTEM_WINDOWS_GUI ? "IMAGE_SUBSYSTEM_WINDOWS_GUI" : x == IMAGE_SUBSYSTEM_WINDOWS_CUI ? "IMAGE_SUBSYSTEM_WINDOWS_CUI"\
 : x == IMAGE_SUBSYSTEM_OS2_CUI ? "IMAGE_SUBSYSTEM_OS2_CUI" : x == IMAGE_SUBSYSTEM_POSIX_CUI ? "IMAGE_SUBSYSTEM_POSIX_CUI"\
 : x == IMAGE_SUBSYSTEM_NATIVE_WINDOWS ? "IMAGE_SUBSYSTEM_NATIVE_WINDOWS" : x == IMAGE_SUBSYSTEM_WINDOWS_CE_GUI ? "IMAGE_SUBSYSTEM_WINDOWS_CE_GUI"\
 : x == IMAGE_SUBSYSTEM_EFI_APPLICATION ? "IMAGE_SUBSYSTEM_EFI_APPLICATION" : x == IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER ? "IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER"\
 : x == IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER ? "IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER" : x == IMAGE_SUBSYSTEM_EFI_ROM ? "IMAGE_SUBSYSTEM_EFI_ROM"\
 : x == IMAGE_SUBSYSTEM_XBOX ? "IMAGE_SUBSYSTEM_XBOX" : x == IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION ? "IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION"\
 : "IMAGE_SUBSYSTEM_UNKNOWN")


namespace ExeViewer
{
    std::string DetermineCharacteristics(std::uint32_t Characteristics)
    {
        std::string Output;
        
        if (Characteristics & IMAGE_FILE_RELOCS_STRIPPED)         Output += "RELOCS_STRIPPED ";
        if (Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE)        Output += "EXECUTABLE_IMAGE ";
        if (Characteristics & IMAGE_FILE_LINE_NUMS_STRIPPED)      Output += "LINE_NUMS_STRIPPED ";
        if (Characteristics & IMAGE_FILE_LOCAL_SYMS_STRIPPED)     Output += "LOCAL_SYMS_STRIPPED ";
        if (Characteristics & IMAGE_FILE_AGGRESIVE_WS_TRIM)       Output += "AGGRESIVE_WS_TRIM ";
        if (Characteristics & IMAGE_FILE_LARGE_ADDRESS_AWARE)     Output += "LARGE_ADDRESS_AWARE ";
        if (Characteristics & IMAGE_FILE_BYTES_REVERSED_LO)       Output += "BYTES_REVERSED_LO ";
        if (Characteristics & IMAGE_FILE_32BIT_MACHINE)           Output += "32BIT_MACHINE ";
        if (Characteristics & IMAGE_FILE_DEBUG_STRIPPED)          Output += "DEBUG_STRIPPED ";
        if (Characteristics & IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP) Output += "REMOVABLE_RUN_FROM_SWAP ";
        if (Characteristics & IMAGE_FILE_NET_RUN_FROM_SWAP)       Output += "NET_RUN_FROM_SWAP ";
        if (Characteristics & IMAGE_FILE_SYSTEM)                  Output += "SYSTEM ";
        if (Characteristics & IMAGE_FILE_DLL)                     Output += "DLL ";
        if (Characteristics & IMAGE_FILE_UP_SYSTEM_ONLY)          Output += "UP_SYSTEM_ONLY ";
        if (Characteristics & IMAGE_FILE_BYTES_REVERSED_HI)       Output += "BYTES_REVERSED_HI ";

        return Output.empty() ? "NONE\n" : Output;
    }


    std::string DetermineDLLCharacteristics(std::uint16_t DC)
    {
        std::string Output;
        
        // Используем побитовое И (&) для каждого флага
        if (DC & IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA)       Output += "HIGH_ENTROPY_VA ";
        if (DC & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE)          Output += "DYNAMIC_BASE ";
        if (DC & IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY)       Output += "FORCE_INTEGRITY ";
        if (DC & IMAGE_DLLCHARACTERISTICS_NX_COMPAT)             Output += "NX_COMPAT ";
        if (DC & IMAGE_DLLCHARACTERISTICS_NO_ISOLATION)          Output += "NO_ISOLATION ";
        if (DC & IMAGE_DLLCHARACTERISTICS_NO_SEH)                Output += "NO_SEH ";
        if (DC & IMAGE_DLLCHARACTERISTICS_NO_BIND)               Output += "NO_BIND ";
        if (DC & IMAGE_DLLCHARACTERISTICS_APPCONTAINER)          Output += "APPCONTAINER ";
        if (DC & IMAGE_DLLCHARACTERISTICS_WDM_DRIVER)            Output += "WDM_DRIVER ";
        if (DC & IMAGE_DLLCHARACTERISTICS_GUARD_CF)              Output += "GUARD_CF ";
        if (DC & IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE) Output += "TERMINAL_SERVER_AWARE ";

        return Output.empty() ? "" : Output;
    }
};


//template <>
//struct std::formatter<std::byte> {
//    auto format(std::byte b, std::format_context& ctx) const {
//        return std::format_to(ctx.out(), "0x{:02x}", std::to_integer<int>(b));
//    }
//};


template <>
struct std::formatter<ExeViewer::IMAGE_DOS_HEADER> : std::formatter<std::string_view>
{
    auto format(const ExeViewer::IMAGE_DOS_HEADER& IDH, std::format_context& CTX) const
    {
        return std::format_to(CTX.out(),
            "IMAGE_DOS_HEADER::e_magic={0:#010X}=>{1}\n"
            "IMAGE_DOS_HEADER::e_cblp={2:#010X}=>{2:d}\n"
            "IMAGE_DOS_HEADER::e_cp={3:#010X}=>{3:d}\n"
            "IMAGE_DOS_HEADER::e_crlc={4:#010X}=>{4:d}\n"
            "IMAGE_DOS_HEADER::e_cparhdr={5:#010X}=>{5:d}\n"
            "IMAGE_DOSC_HEADER::e_minalloc={6:#010X}=>{6:d}\n"
            "IMAGE_DOS_HEADER::e_maxalloc={7:#010X}=>{7:d}\n"
            "IMAGE_DOS_HEADER::e_ss={8:#010X}=>{8:d}\n"
            "IMAGE_DOS_HEADER::e_sp={9:#010X}=>{9:d}\n"
            "IMAGE_DOS_HEADER::e_csum={10:#010X}=>{10:d}\n"
            "IMAGE_DOS_HEADER::e_ip={11:#010X}=>{11:d}\n"
            "IMAGE_DOS_HEADER::e_cs={12:#010X}=>{12:d}\n"
            "IMAGE_DOS_HEADER::e_lfarlc={13:#010X}=>{13:d}\n"
            "IMAGE_DOS_HEADER::e_ovno={14:#010X}=>{14:d}\n"
            "IMAGE_DOS_HEADER::e_res[0]={15:#010X}=>{15:d}\n"
            "IMAGE_DOS_HEADER::e_res[1]={16:#010X}=>{16:d}\n"
            "IMAGE_DOS_HEADER::e_res[2]={17:#010X}=>{17:d}\n"
            "IMAGE_DOS_HEADER::e_res[3]={18:#010X}=>{18:d}\n"
            "IMAGE_DOS_HEADER::e_oemid={19:#010X}=>{19:d}\n"
            "IMAGE_DOS_HEADER::e_oeminfo={20:#010X}=>{20:d}\n"
            "IMAGE_DOS_HEADER::e_res2[0]={21:#010X}=>{21:d}\n"
            "IMAGE_DOS_HEADER::e_res2[1]={22:#010X}=>{22:d}\n"
            "IMAGE_DOS_HEADER::e_res2[2]={23:#010X}=>{23:d}\n"
            "IMAGE_DOS_HEADER::e_res2[3]={24:#010X}=>{24:d}\n"
            "IMAGE_DOS_HEADER::e_res2[4]={25:#010X}=>{25:d}\n"
            "IMAGE_DOS_HEADER::e_res2[5]={26:#010X}=>{26:d}\n"
            "IMAGE_DOS_HEADER::e_res2[6]={27:#010X}=>{27:d}\n"
            "IMAGE_DOS_HEADER::e_res2[7]={28:#010X}=>{28:d}\n"
            "IMAGE_DOS_HEADER::e_res2[8]={29:#010X}=>{29:d}\n"
            "IMAGE_DOS_HEADER::e_res2[9]={30:#010X}=>{30:d}\n"
            "IMAGE_DOS_HEADER::e_lfanew={31:#010X}=>{31:d}"

            , IDH.e_magic
            , IDH.e_magic == 0x5a4d ? "MZ" : "UNKNOWN"
            , IDH.e_cblp
            , IDH.e_cp
            , IDH.e_crlc
            , IDH.e_cparhdr
            , IDH.e_minalloc
            , IDH.e_maxalloc
            , IDH.e_ss
            , IDH.e_sp
            , IDH.e_csum
            , IDH.e_ip
            , IDH.e_cs      
            , IDH.e_lfarlc
            , IDH.e_ovno
            , IDH.e_res[0]
            , IDH.e_res[1]
            , IDH.e_res[2]
            , IDH.e_res[3]
            , IDH.e_oemid
            , IDH.e_oeminfo
            , IDH.e_res2[0]
            , IDH.e_res2[1]
            , IDH.e_res2[2]
            , IDH.e_res2[3]
            , IDH.e_res2[4]
            , IDH.e_res2[5]
            , IDH.e_res2[6]
            , IDH.e_res2[7]
            , IDH.e_res2[8]
            , IDH.e_res2[9]
            , IDH.e_lfanew
        );
    }
};


template <>
struct std::formatter<ExeViewer::IMAGE_FILE_HEADER> : std::formatter<std::string_view>
{
    auto format(const ExeViewer::IMAGE_FILE_HEADER& IFH, std::format_context& CTX) const
    {
        return std::format_to(CTX.out(),
            "IMAGE_FILE_HEADER::Machine={0:#010X}=>{1}\n"
            "IMAGE_FILE_HEADER::NumberOfSections={2:#010X}=>{2:#d}\n"
            "IMAGE_FILE_HEADER::TimeDateStamp={3:#010X}=>{4:%Y.%m.%d %T%z}\n"
            "IMAGE_FILE_HEADER::PointerToSymbolTable={5:#010X}=>{5:#d}\n"
            "IMAGE_FILE_HEADER::NumberOfSymbols={6:#010X}=>{6:#d}\n"
            "IMAGE_FILE_HEADER::SizeOfOptionalHeader={7:#010X}=>{7:#d}\n"
            "IMAGE_FILE_HEADER::Characteristics={8:#010X}=>{9}\n"
            , IFH.Machine
            , DETERMINE_MACHINE(IFH.Machine)
            , IFH.NumberOfSections
            , IFH.TimeDateStamp
            , std::chrono::sys_seconds{std::chrono::seconds{IFH.TimeDateStamp}}
            , IFH.PointerToSymbolTable
            , IFH.NumberOfSymbols
            , IFH.SizeOfOptionalHeader
            , IFH.Characteristics
            , ExeViewer::DetermineCharacteristics(IFH.Characteristics)
        );
    }
};


template <>
struct std::formatter<ExeViewer::IMAGE_DATA_DIRECTORY> : std::formatter<std::string_view>
{
    auto format(const ExeViewer::IMAGE_DATA_DIRECTORY& IDD, std::format_context& CTX) const
    {
        return std::format_to(CTX.out(),
            "IMAGE_DATA_DIRECTORY::VirtualAddress={0:#010X}=>{0}\n"
            "IMAGE_DATA_DIRECTORY::Size={1:#010X}=>{1:#d}"

            , IDD.VirtualAddress
            , IDD.Size
        );
    }
};


template <>
struct std::formatter<ExeViewer::IMAGE_OPTIONAL_HEADER64> : std::formatter<std::string_view>
{
    auto format(const ExeViewer::IMAGE_OPTIONAL_HEADER64& IOH, std::format_context& CTX) const
    {
        return std::format_to(CTX.out(),
            "IMAGE_OPTIONAL_HEADER64::Magic={0:#010X}=>{1}\n"
            "IMAGE_OPTIONAL_HEADER64::MajorLinkerVersion={2:#010X}=>{3:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::MinorLinkerVersion={4:#010X}=>{5:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::SizeOfCode={6:#010X}=>{6:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::SizeOfInitializedData={7:#010X}=>{7:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::SizeOfUninitializedData={8:#010X}=>{8:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::AddressOfEntryPoint={9:#010X}=>{9:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::BaseOfCode={10:#010X}=>{10:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::ImageBase={11:#010X}=>{11:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::SectionAlignment={12:#010X}=>{12:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::FileAlignment={13:#010X}=>{13:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::MajorOperatingSystemVersion={14:#010X}=>{14:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::MinorOperatingSystemVersion={15:#010X}=>{15:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::MajorImageVersion={16:#010X}=>{16:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::MinorImageVersion={17:#010X}=>{17:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::MajorSubsystemVersion={18:#010X}=>{18:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::MinorSubsystemVersion={19:#010X}=>{19:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::Win32VersionValue={20:#010X}=>{20:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::SizeOfImage={21:#010X}=>{21:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::SizeOfHeaders={22:#010X}=>{22:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::CheckSum={23:#010X}=>{23:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::Subsystem={24:#010X}=>{25}\n"
            "IMAGE_OPTIONAL_HEADER64::DllCharacteristics={26:#010X}=>{27}\n"
            "IMAGE_OPTIONAL_HEADER64::SizeOfStackReserve={28:#010X}=>{28:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::SizeOfStackCommit={29:#010X}=>{29:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::SizeOfHeapReserve={30:#010X}=>{30:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::SizeOfHeapCommit={31:#010X}=>{31:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::LoaderFlags={32:#010X}=>{32:#d}\n"
            "IMAGE_OPTIONAL_HEADER64::NumberOfRvaAndSizes={33:#010X}=>{33:#d}"

            , IOH.Magic
            , IOH.Magic == IMAGE_PEP_TYPE ? "PE+" : "PE"
            , std::to_integer<int>(IOH.MajorLinkerVersion)
            , std::to_integer<int>(IOH.MajorLinkerVersion)
            , std::to_integer<int>(IOH.MinorLinkerVersion)
            , std::to_integer<int>(IOH.MinorLinkerVersion)
            , IOH.SizeOfCode
            , IOH.SizeOfInitializedData
            , IOH.SizeOfUninitializedData
            , IOH.AddressOfEntryPoint
            , IOH.BaseOfCode            
            , IOH.ImageBase
            , IOH.SectionAlignment
            , IOH.FileAlignment
            , IOH.MajorOperatingSystemVersion
            , IOH.MinorOperatingSystemVersion
            , IOH.MajorImageVersion
            , IOH.MinorImageVersion
            , IOH.MajorSubsystemVersion
            , IOH.MinorSubsystemVersion
            , IOH.Win32VersionValue
            , IOH.SizeOfImage
            , IOH.SizeOfHeaders
            , IOH.CheckSum
            , IOH.Subsystem
            , DETERMINE_SUBSYSTEM(IOH.Subsystem)
            , IOH.DllCharacteristics
            , ExeViewer::DetermineDLLCharacteristics(IOH.DllCharacteristics)
            , IOH.SizeOfStackReserve
            , IOH.SizeOfStackCommit
            , IOH.SizeOfHeapReserve
            , IOH.SizeOfHeapCommit
            , IOH.LoaderFlags
            , IOH.NumberOfRvaAndSizes
        );
    }
};


template <>
struct std::formatter<ExeViewer::IMAGE_OPTIONAL_HEADER32> : std::formatter<std::string_view>
{
    auto format(const ExeViewer::IMAGE_OPTIONAL_HEADER32& IOH, std::format_context& CTX) const
    {
        return std::format_to(CTX.out(),
            "IMAGE_OPTIONAL_HEADER32::Magic={0:#010X}=>{1}\n"
            "IMAGE_OPTIONAL_HEADER32::MajorLinkerVersion={2:#010X}=>{3:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::MinorLinkerVersion={4:#010X}=>{5:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::SizeOfCode={6:#010X}=>{6:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::SizeOfInitializedData={7:#010X}=>{7:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::SizeOfUninitializedData={8:#010X}=>{8:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::AddressOfEntryPoint={9:#010X}=>{9:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::BaseOfCode={10:#010X}=>{10:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::BaseOfData={11:#010X}=>{11:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::ImageBase={12:#010X}=>{12:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::SectionAlignment={13:#010X}=>{13:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::FileAlignment={14:#010X}=>{14:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::MajorOperatingSystemVersion={15:#010X}=>{15:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::MinorOperatingSystemVersion={16:#010X}=>{16:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::MajorImageVersion={17:#010X}=>{17:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::MinorImageVersion={18:#010X}=>{18:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::MajorSubsystemVersion={19:#010X}=>{19:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::MinorSubsystemVersion={20:#010X}=>{20:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::Win32VersionValue={21:#010X}=>{21:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::SizeOfImage={22:#010X}=>{22:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::SizeOfHeaders={23:#010X}=>{23:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::CheckSum={24:#010X}=>{24:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::Subsystem={25:#010X}=>{26}\n"
            "IMAGE_OPTIONAL_HEADER32::DllCharacteristics={27:#010X}=>{28}\n"
            "IMAGE_OPTIONAL_HEADER32::SizeOfStackReserve={29:#010X}=>{29:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::SizeOfStackCommit={30:#010X}=>{30:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::SizeOfHeapReserve={31:#010X}=>{31:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::SizeOfHeapCommit={32:#010X}=>{32:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::LoaderFlags={33:#010X}=>{33:#d}\n"
            "IMAGE_OPTIONAL_HEADER32::NumberOfRvaAndSizes={34:#010X}=>{34:#d}"

            , IOH.Magic
            , IOH.Magic == IMAGE_PEP_TYPE ? "PE+" : "PE"
            , std::to_integer<int>(IOH.MajorLinkerVersion)
            , std::to_integer<int>(IOH.MajorLinkerVersion)
            , std::to_integer<int>(IOH.MinorLinkerVersion)
            , std::to_integer<int>(IOH.MinorLinkerVersion)
            , IOH.SizeOfCode
            , IOH.SizeOfInitializedData
            , IOH.SizeOfUninitializedData
            , IOH.AddressOfEntryPoint
            , IOH.BaseOfCode
            , IOH.BaseOfData
            , IOH.ImageBase
            , IOH.SectionAlignment
            , IOH.FileAlignment
            , IOH.MajorOperatingSystemVersion
            , IOH.MinorOperatingSystemVersion
            , IOH.MajorImageVersion
            , IOH.MinorImageVersion
            , IOH.MajorSubsystemVersion
            , IOH.MinorSubsystemVersion
            , IOH.Win32VersionValue
            , IOH.SizeOfImage
            , IOH.SizeOfHeaders
            , IOH.CheckSum
            , IOH.Subsystem
            , DETERMINE_SUBSYSTEM(IOH.Subsystem)
            , IOH.DllCharacteristics
            , ExeViewer::DetermineDLLCharacteristics(IOH.DllCharacteristics)
            , IOH.SizeOfStackReserve
            , IOH.SizeOfStackCommit
            , IOH.SizeOfHeapReserve
            , IOH.SizeOfHeapCommit
            , IOH.LoaderFlags
            , IOH.NumberOfRvaAndSizes
        );
    }
};


template <>
struct std::formatter<ExeViewer::IMAGE_NT_HEADERS64> : std::formatter<std::string_view>
{
    auto format(const ExeViewer::IMAGE_NT_HEADERS64& INH, std::format_context& CTX) const
    {
        return std::format_to(CTX.out(),
            "IMAGE_NT_HEADERS64::Signature={0:#010X}=>PE\n"
            "{1}{2}"

            , INH.Signature
            , INH.FileHeader
            , INH.OptionalHeader
        );
    }
};


template <>
struct std::formatter<ExeViewer::IMAGE_NT_HEADERS32> : std::formatter<std::string_view>
{
    auto format(const ExeViewer::IMAGE_NT_HEADERS32& INH, std::format_context& CTX) const
    {
        return std::format_to(CTX.out(),
            "IMAGE_NT_HEADERS32::Signature={0:#010X}=>PE\n"
            "{1}{2}"

            , INH.Signature
            , INH.FileHeader
            , INH.OptionalHeader
        );
    }
};
