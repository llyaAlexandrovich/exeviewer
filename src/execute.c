#include "execute.h"







/**
 * Executing Process
 * 
 * 1 - Checking for file size to be greater than NUMBER_OF_BYTES_IN_FILE.
 * 2 - Reading entry(NUMBER_OF_BYTES_IN_ENTRY) part of the file.
 * 3 - 
 */
void TryExecuteViewer(char* const filename)
{
    // Check file size.
    unsigned long long filesize = 0;
    if((filesize = CheckFileSize(filename)) == 0)
    {
        return;
    }

    // Read entry part of the file.
    char entrybuffer[NUMBER_OF_BYTES_IN_ENTRY + 1];
    if(ReadFileEntry(filename, entrybuffer) == -1)
    {
        return;
    }

    // Check file type. Its always faster to do what extension say
    // but we still checking file type(magic number) anyway.
    if(GetFileExtension(filename) == exe)
    {
        if(bIsFilePEExecutable(entrybuffer))
        {
            
        }
    }
    else{
        return;
    }


}



unsigned long long CheckFileSize(char* const filename)
{
    // Get file size.
    unsigned long long filesize = GetFileSize(filename);
    if((filesize = GetFileSize(filename)) == 0)
    {
        return (unsigned long long)0;
    }

    // If file size is less than NUMBER_OF_BYTES_IN_FILE exit.
    if(filesize <= NUMBER_OF_BYTES_IN_FILE)
    {
        return (unsigned long long)0;
    }
    return filesize;
}



/**
 * Checking Process
 * 
 * 1 - Check for file extension and perform checks assuming file
 *     type from file extension.
 */
int CheckFileType(char* const filename, char* buffer)
{
    // Get file extension.
    int fileextension = 0;
    if((fileextension = GetFileExtension(filename)) == -1)
    {
        return -1;
    }

    switch(fileextension)
    {
        case unrecognized:
            return unrecognized;

        case exec_pe:
            if(!bIsFilePEExecutable(buffer))
            {
                break;
            }

            int peformat = DeterminePEFormat(buffer);

            if(peformat == -1)
            {
                return -1;
            }
            else if(peformat == IMAGE_PE_TYPE)
            {

            }
            else if(peformat == IMAGE_PEP_TYPE)
            {
                
            }
            

            break;

        case exec_pep:
            break;
        
        default:
            return unrecognized;
    }

}
