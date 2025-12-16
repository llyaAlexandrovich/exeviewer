#include "execute.h"








int TryExecuteViewer(char* const filename, bool doshowless, bool supportcheck)
{
    // Check file size.
    unsigned long long filesize = 0;
    if((filesize = CheckFileSize(filename)) == 0)
    {
        return -1;
    }

    // Read entry part of the file.
    char entrybuffer[NUMBER_OF_BYTES_IN_ENTRY + 1];
    if(ReadFileEntry(filename, entrybuffer) == -1)
    {
        return -1;
    }

    int filetype = 0;
    if((filetype = CheckFileType(filename, entrybuffer)) == -1)
    {
        return -1;
    }

    if(filetype == unrecognized)
    {
        return 1;
    }
    else if(filetype == exec_pe)
    {
        // Create internal directory for PE related executables.
        PEExecutablesData* pex = malloc(sizeof(PEExecutablesData));
        if(pex == NULL)
        {
            return -1;
        }

        // Create buffer for entire file data.
        pex->buffer = malloc(filesize);
        if(pex->buffer == NULL)
        {
            return -1;
        }

        // Create IMAGE_DOS_HEADER structure.
        pex->idh = malloc(sizeof(IMAGE_DOS_HEADER));
        if(pex->idh == NULL)
        {
            return -1;
        }

        // Fill remaining structure data.
        pex->filename     = filename;
        pex->doshowless   = doshowless;
        pex->supportcheck = supportcheck;
        pex->arch         = IMAGE_X32;

        // 
        GetInfoOfPEExecutable(pex);

        // Clearing resources.
        free(pex->buffer);
        free(pex->idh);
        free(pex->inh.low);
        free(pex);
        return 0;
    }
    else if(filetype == exec_pep)
    {
        // Create internal directory for PE related executables.
        PEExecutablesData* pex = malloc(sizeof(PEExecutablesData));
        if(pex == NULL)
        {
            return -1;
        }

        // Create buffer for entire file data.
        pex->buffer = malloc(filesize);
        if(pex->buffer == NULL)
        {
            return -1;
        }

        // Create IMAGE_DOS_HEADER structure.
        pex->idh = malloc(sizeof(IMAGE_DOS_HEADER));
        if(pex->idh == NULL)
        {
            return -1;
        }

        // Fill remaining structure data.
        pex->filename     = filename;
        pex->doshowless   = doshowless;
        pex->supportcheck = supportcheck;
        pex->arch         = IMAGE_X64;

        // 
        GetInfoOfPEExecutable(pex);

        // Clearing resources.
        free(pex->buffer);
        free(pex->idh);
        free(pex->inh.high);
        free(pex);
        return 0;
    }

    return 0;
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



int CheckFileType(char* const filename, char* buffer)
{
    // Get file extension.
    int fileextension = 0;
    if((fileextension = GetFileExtension(filename)) == -1)
    {
        return -1;
    }

    // Trying to figure out file type by file extension.
    switch(fileextension)
    {
        // File extension unrecognized.
        case unrecognized:
            return unrecognized;

        // File extension = .exe .
        case exe:
            if(!bIsFilePEExecutable(buffer))
            {
                break; // File magic bytes not recognied as PE executable.
            }

            int peformat = DeterminePEFormat(buffer); // Trying to figure out whether file is x32 or x64.

            if(peformat == -1) // DeterminePEFormat funtion error.
            {
                return -1;
            }
            else if(peformat == IMAGE_PE_TYPE) // x32.
            {
                return exec_pe;
            }
            else if(peformat == IMAGE_PEP_TYPE) // x64.
            {
                return exec_pep;
            }
            break;
        
        // Plug to avoid errors.
        default:
            return unrecognized;
    }

    return unrecognized; // This return should not be reached.
}



void GetInfoOfPEExecutable(PEExecutablesData* pex)
{
    if(pex->arch == IMAGE_X32)
    {
        pex->inh.low = malloc(sizeof(IMAGE_NT_HEADERS32));

        FillOutNTEntireStructureLow(pex->idh, pex->inh.low, pex->buffer);

        if(!pex->doshowless)
        {
            PrintHeadersDataLow(pex->idh, pex->inh.low, pex->buffer);
        }
    }
    else if(pex->arch == IMAGE_X64)
    {
        pex->inh.high = malloc(sizeof(IMAGE_NT_HEADERS64));

        FillOutNTEntireStructureHigh(pex->idh, pex->inh.high, pex->buffer);

        if(!pex->doshowless)
        {
            PrintHeadersDataHigh(pex->idh, pex->inh.high, pex->buffer);
        }
    }
}
