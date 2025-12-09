#include "fileread.h"








int ReadFileEntry(const char* filename, char* filebuffer)
{
    FILE* fd = fopen(filename, "rb"); // Getting file descriptor.
    if(fd == -1)
    {
        return -1;
    }

    ssize_t bytesread = fread((void*)filebuffer, sizeof(char), NUMBER_OF_BYTES_IN_ENTRY, fd); // Trying to read file.
    if(bytesread == 0)
    {
        return -1;
    }

    fclose(fd); // Closing file descriptor.

    return 0;
}



int ReadFile(const char* filename, char* filebuffer)
{
    unsigned long long size = GetFileSize(filename); // Getting file size.
    if(size == -1)
    {
        return -1;
    }

    FILE* fd = fopen(filename, "rb"); // Getting file descriptor.
    if(fd == -1)
    {
        return -1;
    }

    ssize_t bytesread = fread((void*)filebuffer, sizeof(char), size, filebuffer); // Trying to read file.
    if(bytesread == 0)
    {
        return -1;
    }

    fclose(fd); // Closing file descriptor.

    return 0;
}



unsigned long long GetFileSize(const char* filename)
{
    FILE* fd = fopen(filename, "rb"); // Getting file descriptor.
    if(fd == -1)
    {
        return (unsigned long long)-1;
    }

    fseek(fd, 0, SEEK_END); // Processing file size.

    unsigned long long size = ftell(fd); // Getting file size.

    fclose(fd); // Closing file descriptor.

    return size;
}