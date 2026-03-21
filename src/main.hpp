#pragma once



#include <iostream>
#include <string>
#include <format>
#include <vector>
#include <memory>


#include "format/exe/exe.hpp"



#define VERSION "1.0.0-stable"


int main(int argc, char **argv);



/**
 * Arguments
 * 
 * -E --exec  file to execute program with
 * -SL --show-less  omit 'useless' data from the output
 * -H --help  showing help page
 */
static std::string HelpPage = std::format(
    "ExeViewer by Ilya Alexandrovich\n"
    "Version = {}\n"
    "Help page =>\n"
    "* -E --exec  file to execute program with\n"
    "* -H --help  showing help page"
    , VERSION
);

//     "\t* -SL --show-less  omit 'useless' data from the output"