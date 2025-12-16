#include "execute.h"







/**
 * 1. Check file size. File size should be at least NUMBER_OF_BYTES_IN_FILE(50000) bytes.
 * 2. Initialize PEExecutablesData structure.
 * 3. Read entry NUMBER_OF_BYTES_IN_ENTRY(80) bytes. That's should be enough to determine if
 *    file actually supported or not.
 * 4. Determine if given file is actually supported(by magic bytes(signature)).
 * 5. Read file fully.
 */
int TryExecuteViewer(char* const filename, bool doshowless, bool supportcheck)
{
    // Check file size.
    unsigned long long filesize = 0;
    if(CheckFileSize(filename, &filesize) == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }

    // Checking if the file meets the required conditions.
    if(filesize <= NUMBER_OF_BYTES_IN_FILE)
    {
        return EXIT_FAILURE;
    }


    // Initialize PEExecutablesData structure.
    PEExecutablesData pds;
    pds.doshowless   = doshowless;
    pds.supportcheck = supportcheck;
    pds.filename     = filename;
    pds.buffer = malloc(NUMBER_OF_BYTES_IN_ENTRY * sizeof(char));

    // Check for memory to be allocated.
    if(pds.buffer == NULL)
    {
        return EXIT_FAILURE;
    }


    // Read entry part of the file.
    if(ReadFileEntry(pds.filename, pds.buffer) == EXIT_FAILURE)
    {
        free(pds.buffer);
        return EXIT_FAILURE;
    }


    // Determine if file signature is supported.
    if(!bIsFileRecognizedExecutable(pds.buffer))
    {
        free(pds.buffer);
        return EXIT_FAILURE;
    }


    // Create real buffer and write the whole file in it.
    free(pds.buffer);

    pds.buffer = malloc(filesize * sizeof(char));
    if(pds.buffer == NULL)
    {
        return EXIT_FAILURE;
    }

    if(ReadFile(pds.filename, pds.buffer) == EXIT_FAILURE)
    {
        free(pds.buffer);
        return EXIT_FAILURE;
    }
    

    // Determine file type.
    int filetype = 0;
    if(DetermineFileType(pds.filename, pds.buffer, &filetype) == EXIT_FAILURE)
    {
        free(pds.buffer);
        return EXIT_FAILURE;
    }
    

    switch(filetype)
    {
        case unrecognized:
            free(pds.buffer);
            ShowSupportedFormatsText();
            return EXIT_SUCCESS;

        case exec_pe:
            // Set up x32 arch.
            pds.arch = IMAGE_X32;


            // Get info of exe file.
            GetInfoOfPEExecutable(&pds);


            // Print info to the console if not omitted.
            if(!pds.doshowless)
            {
                PrintInfoOfPEExecutable(&pds);
            }


            // Freeing resources.
            free(pds.buffer);


            return EXIT_SUCCESS;

        case exec_pep:
            // Set up x32 arch.
            pds.arch = IMAGE_X64;


            // Get info of exe file.
            GetInfoOfPEExecutable(&pds);


            // Print info to the console if not omitted.
            if(!pds.doshowless)
            {
                PrintInfoOfPEExecutable(&pds);
            }


            // Freeing resources.
            free(pds.buffer);


            return EXIT_SUCCESS;

        default:
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}



int CheckFileSize(char* const filename, unsigned long long* filesize)
{
    // Get file size.
    if(GetFileSize(filename, filesize) == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }

    // If file size is less than NUMBER_OF_BYTES_IN_FILE exit.
    if((*filesize) <= NUMBER_OF_BYTES_IN_FILE)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}



int DetermineFileType(char* const filename, char* buffer, int* filetype)
{
    // Get file extension.
    int fileextension = 0;
    if(GetFileExtension(filename, &fileextension) == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }

    // Trying to figure out file type by file extension.
    switch(fileextension)
    {
        // File extension unrecognized.
        case unrecognized:
            (*filetype) = unrecognized;
            return EXIT_SUCCESS;

        // File extension = .exe .
        case exe:
            if(!bIsFilePEExecutable(buffer))
            {
                break; // File magic bytes not recognied as PE executable.
            }

            int peformat = DeterminePEFormat(buffer); // Trying to figure out whether file is x32 or x64.

            if(peformat == EXIT_FAILURE) // DeterminePEFormat funtion error.
            {
                return EXIT_FAILURE;
            }
            else if(peformat == IMAGE_PE_TYPE) // x32.
            {
                (*filetype) = exec_pe;
                return EXIT_SUCCESS;
            }
            else if(peformat == IMAGE_PEP_TYPE) // x64.
            {
                (*filetype) = exec_pep;
                return EXIT_SUCCESS;
            }
            break;
        
        // Plug to avoid errors.
        default:
            (*filetype) = unrecognized;
            return EXIT_SUCCESS;
    }

    // Fallback to default format detection.
    if(bIsFilePEExecutable(buffer))
    {
        return (DeterminePEFormat(buffer) == IMAGE_PE_TYPE) ? ((*filetype) = exec_pe, EXIT_SUCCESS) : ((*filetype) = exec_pep, EXIT_SUCCESS); 
    }

    // This return should not be reached.
    (*filetype) = unrecognized;
    return EXIT_SUCCESS;
}



void GetInfoOfPEExecutable(PEExecutablesData* pds)
{
    if(pds->arch == IMAGE_X32)
    {
        FillOutNTEntireStructureLow(&pds->idh, &pds->inh.low, pds->buffer);
    }
    else if(pds->arch == IMAGE_X64)
    {
        FillOutNTEntireStructureHigh(&pds->idh, &pds->inh.high, pds->buffer);
    }
}



void PrintInfoOfPEExecutable(PEExecutablesData* pds)
{
    if(pds->arch == IMAGE_X32)
    {
        PrintHeadersDataLow(&pds->idh, &pds->inh.low, pds->buffer);
    }
    else if(pds->arch == IMAGE_X64)
    {
        PrintHeadersDataHigh(&pds->idh, &pds->inh.high, pds->buffer);
    }
}



bool bIsFileRecognizedExecutable(char* buffer)
{
    if(bIsFilePEExecutable(buffer))
    {
        return true;
    }
    return false;
}
