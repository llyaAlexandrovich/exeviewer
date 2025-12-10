#include "format.h"








int RecognizeFileFormat(char* buffer)
{
    // Determine magic number from file data.
    // MZ(0x4D5A). DOS header.
    if(bIsFilePEExecutable(buffer))
    {
        if(DeterminePEFormat(buffer) == IMAGE_PE_TYPE) // x32
        {
            return exec_pe;
        }
        else if(DeterminePEFormat(buffer) == IMAGE_PEP_TYPE) // x64
        {
            return exec_pep;
        }
    }
    // Unrecognized format.
    else
    {
        return unrecognized;
    }
}
