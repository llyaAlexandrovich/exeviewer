#include "fileread.h"








int ReadFileEntry(char* const filename, char* filebuffer)
{
    FILE* fd = fopen(filename, "rb"); // Getting file descriptor.
    if(fd == NULL)
    {
        return EXIT_FAILURE;
    }

    ssize_t bytesread = fread((void*)filebuffer, sizeof(char), NUMBER_OF_BYTES_IN_ENTRY, fd); // Trying to read file.
    if(bytesread == 0)
    {
        fclose(fd);
        return EXIT_FAILURE;
    }

    fclose(fd); // Closing file descriptor.

    return EXIT_SUCCESS;
}



int ReadFile(char* const filename, char* filebuffer)
{
    unsigned long long size = 0;
    GetFileSize(filename, &size); // Getting file size.
    if(size == 0)
    {
        return EXIT_FAILURE;
    }

    FILE* fd = fopen(filename, "rb"); // Getting file descriptor.
    if(fd == NULL)
    {
        return EXIT_FAILURE;
    }

    ssize_t bytesread = fread((void* restrict)filebuffer, sizeof(char), size, fd); // Trying to read file.
    if(bytesread == 0)
    {
        fclose(fd);
        return EXIT_FAILURE;
    }

    fclose(fd); // Closing file descriptor.

    return EXIT_SUCCESS;
}



int GetFileSize(char* const filename, unsigned long long* filesize)
{
    FILE* fd = fopen(filename, "rb"); // Getting file descriptor.
    if(fd == NULL)
    {
        return EXIT_FAILURE;
    }

    fseek(fd, 0, SEEK_END); // Processing file size.

    (*filesize) = ftell(fd); // Getting file size.

    fclose(fd); // Closing file descriptor.

    return EXIT_SUCCESS;
}



int GetFileExtension(char* const filename, int* fileext)
{
    short filenamesize = sizeof(filename);

    short counter = filenamesize;
    for(; filename[counter] != '.'; --counter);

    if(strcmp(&filename[counter], "exe"))
    {
        (*fileext) = (int)exe;
        return EXIT_SUCCESS;
    }
    else
    {
        (*fileext) = (int)unrecognized;
        return EXIT_SUCCESS;
    }
}
