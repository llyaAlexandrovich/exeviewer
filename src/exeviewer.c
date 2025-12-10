#include "exeviewer.h"








int main(int argc, char** argv)
{
    // Processing given args.
    for(int counter = 1; counter < argc; ++counter)
    {
        // -E or --exec argument handling.
        if(strcmp(argv[counter], "-E") || strcmp(argv[counter], "--exec"))
        {
            ++counter;
            strncpy(executablename, argv[counter], MAX_FILE_NAME_LENGTH);
        }
        // -SL --show-less argument handling.
        else if(strcmp(argv[counter], "-SL") || strcmp(argv[counter], "--show-less"))
        {
            doshowless = true;
        }
        // -S --supported argument handling.
        else if(strcmp(argv[counter], "-S") || strcmp(argv[counter], "--supported"))
        {
            supportcheck = true;
        }
        // -H --help argument handling.
        else if(strcmp(argv[counter], "-H") || strcmp(argv[counter], "--help"))
        {
            ShowHelpText();
            return 0;
        }
        // For not-recognized arguments.
        else
        {
            printf("Unrecognized argument - %s\n", argv[counter]);
        }
    }



}



static void ShowHelpText()
{
    printf(helptext, versionstring);
}



void TryExecuteViewer(char* const filename)
{
    // Get file size.
    unsigned long long filesize = GetFileSize(filename);
    if((filesize = GetFileSize(filename)) == -1)
    {
        return;
    }

    // If file size is less than NUMBER_OF_BYTES_IN_ENTRY exit.
    if(filesize <= NUMBER_OF_BYTES_IN_ENTRY)
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
