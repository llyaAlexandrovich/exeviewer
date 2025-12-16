#pragma once



#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>


#include "../types.h"



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



static const char supportedformatstext[] ="\
File format not recognized\n\
Available formats - .exe\n\
";


static const char versionstring[] = "1.0.6";

static const short versionmajor = 1;
static const short versionminor = 0;
static const short versionpatch = 6;


static char __attribute__((used)) executablename[MAX_FILE_NAME_LENGTH];
static bool __attribute__((used)) doshowless = false;
static bool __attribute__((used)) supportcheck = false;



/** 
 * Show help text to the user.
 * 
 * @author Ilya Alexandrovich
 * 
 * @since 1.0.0
*/
void ShowHelpText();



/**
 * Show supported formats to the user.
 * 
 * @author Ilya Alexandrovich
 * 
 * @since 1.0.0
 */
void ShowSupportedFormatsText();
