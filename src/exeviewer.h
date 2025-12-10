#pragma once



#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>



#include "types.h"
#include "file/fileread.h"
#include "format/format.h"
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



static const char helptext[] = "\
ExeViewer by Ilya Alexandrovich\n\
Version = %s\n\
Help Page\n\
 * NONE => if none of the options below are used\n\
 * pretend like the only given argument is file name\n\
 * -E --exec  file to execute program with\n\
 * -SL --show-less  omit 'useless' data from the output\n\
 * -S --supported  check whether your pc could run executable\n\
 * -H --help  showing help page\n\
";


static const char versionstring[] = "1.0.0";

static const int version = 233;

static const short versionmajor = 1;
static const short versionminor = 0;
static const short versionpatch = 0;


static char executablename[MAX_FILE_NAME_LENGTH];
static bool doshowless = false;
static bool supportcheck = false;



/** 
 * Showing help text to the user.
 * 
 * @author Ilya Alexandrovich
 * 
 * @since 1.0.0
*/
static void ShowHelpText();



/**
 * Trying to start exeviewer on specified file.
 * 
 * @author Ilya Alexandrovich
 * 
 * @param filename  file name to try exeviewer on
 * 
 * @since 1.0.0
 */
void TryExecuteViewer(char* const filename);
