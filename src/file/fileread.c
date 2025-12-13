#include "fileread.h"








int ReadFileEntry(char* const filename, char* filebuffer)
{
    FILE* fd = fopen(filename, "rb"); // Getting file descriptor.
    if(fd == NULL)
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



int ReadFile(char* const filename, char* filebuffer)
{
    unsigned long long size = GetFileSize(filename); // Getting file size.
    if(size == -1)
    {
        return -1;
    }

    FILE* fd = fopen(filename, "rb"); // Getting file descriptor.
    if(fd == NULL)
    {
        return -1;
    }

    ssize_t bytesread = fread((void* restrict)filebuffer, sizeof(char), size, fd); // Trying to read file.
    if(bytesread == 0)
    {
        return -1;
    }

    fclose(fd); // Closing file descriptor.

    return 0;
}



unsigned long long GetFileSize(char* const filename)
{
    FILE* fd = fopen(filename, "rb"); // Getting file descriptor.
    if(fd == NULL)
    {
        return (unsigned long long)0;
    }

    fseek(fd, 0, SEEK_END); // Processing file size.

    unsigned long long size = ftell(fd); // Getting file size.

    fclose(fd); // Closing file descriptor.

    return size;
}



int GetFileExtension(char* const filename)
{
    short filenamesize = sizeof(filename);

    short counter = filenamesize;
    for(; filename[counter] != '.'; --counter);

    if(strcmp(&filename[counter], "exe"))
    {
        return exe;
    }
    else
    {
        return unrecognized;
    }
}
