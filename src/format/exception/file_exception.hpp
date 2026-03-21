#pragma once



#include <iostream>
#include <string>
#include <string_view>
#include <exception>






namespace Exception
{
    class FileNotFoundException final : public std::exception
    {
    public:
        FileNotFoundException() = default;

        const char * what() const noexcept override
        {
            return Message_.data();
        }
    
    private:
        std::string Message_{"File not found"};
    };


    class FileNotSupportedException final : public std::exception
    {
    public:
        FileNotSupportedException() = default;

        const char * what() const noexcept override
        {
            return Message_.data();
        }
    
    private:
        std::string Message_{"File type is not supported"};
    };
};
