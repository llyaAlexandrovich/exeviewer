#pragma once



#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <string_view>
#include <format>
#include <chrono>




#include "../format.hpp"
#include "../file/file.hpp"
#include "../exception/exception.hpp"


#include "exe_info.hpp"
#include "exe_types.hpp"
#include "exe_formatter.hpp"






namespace ExeViewer
{
    class ExeFormat final : public Format
    {
    public:
        ExeFormat(std::string&& FileName)
        {
            File_ = File::File{std::move(FileName)};

            if(File_.GetFileSize() < LEAST_FILE_LENGTH) throw Exception::FileNotSupportedException{};

            ExeInfo_ = std::make_unique<ExeInfo>();

            FileContent_ = File_.GetFileContent();
        }


        void Init() override
        {
            std::memmove(&ExeInfo_->IDH, FileContent_.data(), IMAGE_SIZEOF_DOS_HEADER);

            std::memmove(ExeInfo_->IDHStub.data(), FileContent_.data() + IMAGE_SIZEOF_DOS_HEADER + 1, ExeInfo_->IDH.e_lfanew - IMAGE_SIZEOF_DOS_HEADER);

            std::uint32_t Offset = ExeInfo_->IDH.e_lfanew;

            if(FileContent_[Offset] == 'P' && FileContent_[Offset + 1] == 'E')
            {
                if(FileContent_[Offset + 2] == '+')
                {
                    std::memmove(&ExeInfo_->UIH.inhHigh, FileContent_.data() + Offset, IMAGE_SIZEOF_HEADERS64);
                    ExeInfo_->Type = ExeInfo_->High;
                }
                else
                {
                    std::memmove(&ExeInfo_->UIH.inhLow, FileContent_.data() + Offset, IMAGE_SIZEOF_HEADERS32);
                    ExeInfo_->Type = ExeInfo_->Low;
                }
            }
        }


        void PrintInfo() override
        {
            std::cout << std::format("{}", ExeInfo_->IDH) << std::endl;

            if(ExeInfo_->Type == ExeInfo::High)
            {
                std::cout << std::format("{}", ExeInfo_->UIH.inhHigh) << std::endl;
            }
            else
            {
                std::cout << std::format("{}", ExeInfo_->UIH.inhLow) << std::endl;
            }
        }

    private:
        std::unique_ptr<ExeInfo> ExeInfo_;
        std::string FileContent_;
        File::File File_;
    };
};
