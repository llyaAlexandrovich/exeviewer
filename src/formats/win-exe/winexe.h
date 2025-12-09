#pragma once



#include <stdbool.h>


#include "../../types.h"
#include "winexe_structures.h"
#include "winexe_functions.h"
#include "winexe_struct_filler_functions.h"




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
#define IMAGE_SUBSYSTEM_UNKNOWN                  0   // An unknown subsystem.
#define IMAGE_SUBSYSTEM_NATIVE                   1   // Device drivers and native Windows processes.
#define IMAGE_SUBSYSTEM_WINDOWS_GUI              2   // The Windows graphical user interface (GUI) subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_CUI              3   // The Windows character subsystem.
#define IMAGE_SUBSYSTEM_OS2_CUI                  5   // The OS/2 character subsystem.
#define IMAGE_SUBSYSTEM_POSIX_CUI                7   // The Posix character subsystem.
#define IMAGE_SUBSYSTEM_NATIVE_WINDOWS           8   // Native Win9x driver.
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI           9   // Windows CE.
#define IMAGE_SUBSYSTEM_EFI_APPLICATION          10  // An Extensible Firmware Interface (EFI) application.
#define IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  11   // An EFI driver with boot services.
#define IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER       12  // An EFI driver with run-time services.
#define IMAGE_SUBSYSTEM_EFI_ROM                  13  // An EFI ROM image
#define IMAGE_SUBSYSTEM_XBOX                     14  // XBOX
#define IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION 16   // Windows boot application.
