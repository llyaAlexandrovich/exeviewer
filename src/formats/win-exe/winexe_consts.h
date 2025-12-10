#pragma once



#define IMAGE_PE_TYPE                    0x10b  // PE
#define IMAGE_PEP_TYPE                   0x20b  // PE+


#define IMAGE_SIZEOF_FILE_HEADER         20
#define IMAGE_SIZEOF_SECTION_HEADER      40
#define IMAGE_SIZEOF_OPTIONAL_HEADER32   96
#define IMAGE_SIZEOF_OPTIONAL_HEADER64   112


#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16


#define IMAGE_SIZEOF_SHORT_NAME          8


// Supported machine types.
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
#define IMAGE_DLLCHARACTERISTICS_NO_ISOLATION           0x0200  // Image understands isolation and doesn't want it.
#define IMAGE_DLLCHARACTERISTICS_NO_SEH                 0x0400  // Image does not use SEH. No SE handler may reside in this image.
#define IMAGE_DLLCHARACTERISTICS_NO_BIND                0x0800  // Do not bind this image.
#define IMAGE_DLLCHARACTERISTICS_APPCONTAINER           0x1000  // Image should execute in an AppContainer.
#define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER             0x2000  // A WDM driver.
#define IMAGE_DLLCHARACTERISTICS_GUARD_CF               0x4000  // Image supports Control Flow Guard.
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE  0x8000  // Terminal Server aware.



// Subsystem.
#define IMAGE_SUBSYSTEM_UNKNOWN                  0   // An unknown subsystem.
#define IMAGE_SUBSYSTEM_NATIVE                   1   // Device drivers and native Windows processes.
#define IMAGE_SUBSYSTEM_WINDOWS_GUI              2   // The Windows graphical user interface (GUI) subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_CUI              3   // The Windows character subsystem.
#define IMAGE_SUBSYSTEM_OS2_CUI                  5   // The OS/2 character subsystem.
#define IMAGE_SUBSYSTEM_POSIX_CUI                7   // The Posix character subsystem.
#define IMAGE_SUBSYSTEM_NATIVE_WINDOWS           8   // Native Win9x driver.
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI           9   // Windows CE.
#define IMAGE_SUBSYSTEM_EFI_APPLICATION          10  // An Extensible Firmware Interface (EFI) application.
#define IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  11  // An EFI driver with boot services.
#define IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER       12  // An EFI driver with run-time services.
#define IMAGE_SUBSYSTEM_EFI_ROM                  13  // An EFI ROM image.
#define IMAGE_SUBSYSTEM_XBOX                     14  // XBOX.
#define IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION 16  // Windows boot application.



// Section characteristics.
//      IMAGE_SCN_TYPE_REG                   0x00000000  // Reserved.
//      IMAGE_SCN_TYPE_DSECT                 0x00000001  // Reserved.
//      IMAGE_SCN_TYPE_NOLOAD                0x00000002  // Reserved.
//      IMAGE_SCN_TYPE_GROUP                 0x00000004  // Reserved.
#define IMAGE_SCN_TYPE_NO_PAD                0x00000008  // Reserved.
//      IMAGE_SCN_TYPE_COPY                  0x00000010  // Reserved.
#define IMAGE_SCN_CNT_CODE                   0x00000020  // Section contains code.
#define IMAGE_SCN_CNT_INITIALIZED_DATA       0x00000040  // Section contains initialized data.
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA     0x00000080  // Section contains uninitialized data.
#define IMAGE_SCN_LNK_OTHER                  0x00000100  // Reserved.
#define IMAGE_SCN_LNK_INFO                   0x00000200  // Section contains comments or some other type of information.
//      IMAGE_SCN_TYPE_OVER                  0x00000400  // Reserved.
#define IMAGE_SCN_LNK_REMOVE                 0x00000800  // Section contents will not become part of image.
#define IMAGE_SCN_LNK_COMDAT                 0x00001000  // Section contents comdat.
//                                           0x00002000  // Reserved.
//      IMAGE_SCN_MEM_PROTECTED - Obsolete   0x00004000  // Reserved.
#define IMAGE_SCN_NO_DEFER_SPEC_EXC          0x00004000  // Reset speculative exceptions handling bits in the TLB entries for this section.
#define IMAGE_SCN_GPREL                      0x00008000  // Section content can be accessed relative to GP
#define IMAGE_SCN_MEM_FARDATA                0x00008000  // Reserved.
//      IMAGE_SCN_MEM_SYSHEAP  - Obsolete    0x00010000  // Reserved.
#define IMAGE_SCN_MEM_PURGEABLE              0x00020000  // Reserved.
#define IMAGE_SCN_MEM_16BIT                  0x00020000  // Reserved.
#define IMAGE_SCN_MEM_LOCKED                 0x00040000  // Reserved.
#define IMAGE_SCN_MEM_PRELOAD                0x00080000  // Reserved.
#define IMAGE_SCN_ALIGN_1BYTES               0x00100000  // Align data on a 1-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_2BYTES               0x00200000  // Align data on a 2-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_4BYTES               0x00300000  // Align data on a 4-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_8BYTES               0x00400000  // Align data on an 8-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_16BYTES              0x00500000  // Default alignment if no others are specified.
#define IMAGE_SCN_ALIGN_32BYTES              0x00600000  // Align data on a 32-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_64BYTES              0x00700000  // Align data on a 64-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_128BYTES             0x00800000  // Align data on a 128-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_256BYTES             0x00900000  // Align data on a 256-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_512BYTES             0x00A00000  // Align data on a 512-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_1024BYTES            0x00B00000  // Align data on a 1024-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_2048BYTES            0x00C00000  // Align data on a 2048-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_4096BYTES            0x00D00000  // Align data on a 4096-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_8192BYTES            0x00E00000  // Align data on an 8192-byte boundary. Valid only for object files.
// Unused                                    0x00F00000  // Unsubscribed.
#define IMAGE_SCN_ALIGN_MASK                 0x00F00000  // Unsubscribed.
#define IMAGE_SCN_LNK_NRELOC_OVFL            0x01000000  // Section contains extended relocations.
#define IMAGE_SCN_MEM_DISCARDABLE            0x02000000  // Section can be discarded.
#define IMAGE_SCN_MEM_NOT_CACHED             0x04000000  // Section is not cachable.
#define IMAGE_SCN_MEM_NOT_PAGED              0x08000000  // Section is not pageable.
#define IMAGE_SCN_MEM_SHARED                 0x10000000  // Section is shareable.
#define IMAGE_SCN_MEM_EXECUTE                0x20000000  // Section is executable.
#define IMAGE_SCN_MEM_READ                   0x40000000  // Section is readable.
#define IMAGE_SCN_MEM_WRITE                  0x80000000  // Section is writeable.
