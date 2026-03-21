#pragma once



#include <iostream>
#include <string>
#include <filesystem>


#include "file/file.hpp"


namespace ExeViewer
{
    class Format
    {
    public:
        Format() = default;

        Format(std::string&& FileName)
        {
            File_ = File::File{std::move(FileName)};

            if(File_.GetFileSize() < LEAST_FILE_LENGTH) throw Exception::FileNotSupportedException{};
        }

        virtual ~Format() = default;

        virtual void Init() = 0;

        virtual void PrintInfo() = 0;

    private:
        File::File File_;
    };
};
