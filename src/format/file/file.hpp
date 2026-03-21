#pragma once



#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>
#include <fstream>


#define LEAST_FILE_LENGTH 20'000 // bytes


#include "../exception/exception.hpp"



namespace File
{
    class File final
    {
    public:
        File() = default;

        File(std::string&& FileName)
        : FileName_(FileName)
        {
            FileDescriptor_ = std::fstream{FileName_, std::ios::in | std::ios::out | std::ios::binary};

            if(!FileDescriptor_.is_open()) throw Exception::FileNotFoundException{};

            FileSize_ = std::filesystem::file_size(FileName);
        }


        std::string GetFileContent()
        {
            std::string Output;
            Output.resize(FileSize_);
            FileDescriptor_.read(reinterpret_cast<char*>(Output.data()), FileSize_);
            return std::move(Output);
        }


        // GetFileAttr()


        std::size_t GetFileSize()
        {
            return FileSize_;
        }


    private:
        std::string FileName_;
        std::fstream FileDescriptor_;
        std::size_t FileSize_;
    };
};
