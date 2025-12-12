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
