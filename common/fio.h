#ifndef __FIO_H__
#define __FIO_H__

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "log.h"

static inline const char* read_file_contents(const char* path) {
    FILE* stream;
    stream = fopen(path, "rb");
    if(!stream) LOG_AND_CLOSE(stream, "Couldn't find source file [%s].", path);
    if(fseek(stream, 0L, SEEK_END)) 
        LOG_AND_CLOSE(stream, "Seeking to EOF failed [%s].", path);
    long temp = ftell(stream);
    if(temp < 0) LOG_AND_CLOSE(stream, "Invalid file size [%s].", path);
    size_t file_size = (size_t) temp;
    if(fseek(stream, 0L, SEEK_SET))
        LOG_AND_CLOSE(stream, "Seeking to beginning of file failed [%s].", path);
    char* contents;
    contents = (char*) malloc(file_size + 1);
    if(!(contents = (char*) malloc(file_size + 1)))
        LOG_AND_CLOSE(stream, "Unable to allocate buffer for file contents [%s].", path);
    size_t size = fread(contents,1,file_size, stream);
    if(size < file_size && !feof(stream))
        LOG_AND_CLOSE(stream, "Read less bytes than expected [%s].", path);
    contents[size] = '\0';
    fclose(stream);
    return contents;
}

#endif // __FIO_H__
