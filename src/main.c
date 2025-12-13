#include <stdio.h>
#include <string.h>


#include "types.h"
#include "exeviewer/exeviewer.h"
#include "execute/execute.h"
#include "file/fileread.h"
#include "formats/win-exe/winexe.h"




/**
 * Recognizable arguments.
 * NONE => if none of the options below are used
 * pretend like the only given argument is file name
 * -E --exec  file to execute program with
 * -SL --show-less  omit 'useless' data from the output
 * -S --supported  check whether your pc could run executable
 * -H --help  showing help page
 */
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

    // Try execute given file.
    int executecode = 0;
    if((executecode = TryExecuteViewer(executablename, doshowless, supportcheck)) != 0)
    {
        if(executecode == 1)
        {
            ShowSupportedFormatsText();
            return 0;
        }
        else{
            return 1;
        }
    }

    return 0;
}