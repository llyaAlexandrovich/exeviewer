#include "winexe_functions.h"








void PrintDOSStubText(IMAGE_DOS_HEADER* idh, char* buffer)
{
    for(int counter = 64; counter != idh->e_lfanew; ++counter){
        printf("%c", buffer[counter]);
    }
    printf("\n");
}



int DeterminePEFormat(IMAGE_DOS_HEADER* idh, char* buffer)
{
    long offset = MAKELONG(MAKEWORD(buffer[60], buffer[61]), MAKEWORD(buffer[62], buffer[63]));

    if(buffer[offset] == 'P' && buffer[offset + 1] == 'E'){
        if(buffer[offset + 2] == '+'){
            return IMAGE_PEP_TYPE;
        }
        return IMAGE_PE_TYPE;
    }
    return -1;
}



bool bIsFilePEExecutable(char* buffer)
{
    if(buffer[0] != "4d" || buffer[1] != "5a"){
        return false;
    }

    long offset = MAKELONG(MAKEWORD(buffer[60], buffer[61]), MAKEWORD(buffer[62], buffer[63]));

    if(buffer[offset] == 'P' && buffer[offset + 1] == 'E'){
        return true;
    }
    return false;
}
