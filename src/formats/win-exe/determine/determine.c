#include "determine.h"








char* DetermineTimeDateStamp(DWORD t)
{
    // YOU COULD NOT DO gmtime((const time_t*)&t) on Windows for reasons 
    // I yet didn't understand. It works on linux but not on Windows. 
    // Just live with it. 
    time_t tt = (time_t)t;

    return asctime(gmtime(&tt));
}



void DetermineCharacteristics(volatile DWORD characteristics)
{
    

    for(;characteristics != 0;)
    {
        // So basically we either using -O3 or volatile
        // because otherwise this variable is not gonna
        // appear at run-time ant therefore we get
        // infinite loop. That's bad. 
        volatile long temp = characteristics;

        // IMAGE_FILE_BYTES_REVERSED_HI
        if((temp = characteristics - IMAGE_FILE_BYTES_REVERSED_HI) > 0)
        {
            printf("BYTES_REVERSED_HI ");
            characteristics -= IMAGE_FILE_BYTES_REVERSED_HI;
        }
        // IMAGE_FILE_UP_SYSTEM_ONLY
        else if((temp = characteristics - IMAGE_FILE_UP_SYSTEM_ONLY) > 0)
        {
            printf("UP_SYSTEM_ONLY ");
            characteristics -= IMAGE_FILE_UP_SYSTEM_ONLY;
        }
        // IMAGE_FILE_DLL
        else if((temp = characteristics - IMAGE_FILE_DLL) > 0)
        {
            printf("DLL ");
            characteristics -= IMAGE_FILE_DLL;
        }
        // IMAGE_FILE_SYSTEM
        else if((temp = characteristics - IMAGE_FILE_SYSTEM) > 0)
        {
            printf("SYSTEM ");
            characteristics -= IMAGE_FILE_SYSTEM;
        }
        // IMAGE_FILE_NET_RUN_FROM_SWAP
        else if((temp = characteristics - IMAGE_FILE_NET_RUN_FROM_SWAP) > 0)
        {
            printf("NET_RUN_FROM_SWAP ");
            characteristics -= IMAGE_FILE_NET_RUN_FROM_SWAP;
        }
        // IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP
        else if((temp = characteristics - IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP) > 0)
        {
            printf("REMOVABLE_RUN_FROM_SWAP ");
            characteristics -= IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP;
        }
        // IMAGE_FILE_DEBUG_STRIPPED
        else if((temp = characteristics - IMAGE_FILE_DEBUG_STRIPPED) > 0)
        {
            printf("DEBUG_STRIPPED ");
            characteristics -= IMAGE_FILE_DEBUG_STRIPPED;
        }
        // IMAGE_FILE_32BIT_MACHINE
        else if((temp = characteristics - IMAGE_FILE_32BIT_MACHINE) > 0)
        {
            printf("32BIT_MACHINE ");
            characteristics -= IMAGE_FILE_32BIT_MACHINE;
        }
        // IMAGE_FILE_BYTES_REVERSED_LO
        else if((temp = characteristics - IMAGE_FILE_BYTES_REVERSED_LO) > 0)
        {
            printf("BYTES_REVERSED_LO ");
            characteristics -= IMAGE_FILE_BYTES_REVERSED_LO;
        }
        // IMAGE_FILE_LARGE_ADDRESS_AWARE
        else if((temp = characteristics - IMAGE_FILE_LARGE_ADDRESS_AWARE) > 0)
        {
            printf("LARGE_ADDRESS_AWARE ");
            characteristics -= IMAGE_FILE_LARGE_ADDRESS_AWARE;
        }
        // IMAGE_FILE_AGGRESIVE_WS_TRIM
        else if((temp = characteristics - IMAGE_FILE_AGGRESIVE_WS_TRIM) > 0)
        {
            printf("AGGRESIVE_WS_TRIM ");
            characteristics -= IMAGE_FILE_AGGRESIVE_WS_TRIM;
        }
        // IMAGE_FILE_LOCAL_SYMS_STRIPPED
        else if((temp = characteristics - IMAGE_FILE_LOCAL_SYMS_STRIPPED) > 0)
        {
            printf("LOCAL_SYMS_STRIPPED ");
            characteristics -= IMAGE_FILE_LOCAL_SYMS_STRIPPED;
        }
        // IMAGE_FILE_LINE_NUMS_STRIPPED
        else if((temp = characteristics - IMAGE_FILE_LINE_NUMS_STRIPPED) > 0)
        {
            printf("LINE_NUMS_STRIPPED ");
            characteristics -= IMAGE_FILE_LINE_NUMS_STRIPPED;
        }
        // IMAGE_FILE_EXECUTABLE_IMAGE
        else if((temp = characteristics - IMAGE_FILE_EXECUTABLE_IMAGE) > 0)
        {
            printf("EXECUTABLE_IMAGE ");
            characteristics -= IMAGE_FILE_EXECUTABLE_IMAGE;
        }
        // IMAGE_FILE_RELOCS_STRIPPED
        else if((temp = characteristics - IMAGE_FILE_RELOCS_STRIPPED) > 0)
        {
            printf("RELOCS_STRIPPED ");
            characteristics -= IMAGE_FILE_RELOCS_STRIPPED;
        }
        else
        {
            printf("\n");
            return;
        }
    }

    printf("\n");

    return;
}
