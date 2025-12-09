#include "format.h"








int RecognizeFileFormat(char* buffer)
{
    // Determine magic number from file data.
    // MZ(0x4D5A). DOS header.
    if(buffer[0] == "4d" && buffer[1] == "5a")
    {
        
    }
    // Unrecognized format.
    else
    {
        return unrecognized;
    }
}



int RecognizePEFormat(char* buffer)
{
    
}