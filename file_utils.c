//
// Created by Emmanuel Arop on 9/9/2018.
//
#include "file_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>


int read_file(char* filename, char **buffer) {
    if (access(filename, F_OK ) == -1)
    {
        // File does not exist
       // printf("File does not exist!\n");
        fprintf( stderr, "File does not exist" );
        return 0; // Failure
    }
    FILE* file1;
    file1 = fopen(filename, "r");

    //gets the size of the file
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    *buffer = malloc(size);
    fread(*buffer, size, 1, file1);
    fclose(file1);
    return size;
}


int write_file(char* filename, char* buffer, int size) {
    FILE* file2;
    file2 = fopen(filename, "w");
    fwrite(buffer, size, 1, file2);
    fclose(file2);
    return 1;
}