#include "file_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv) {
    char* buffer;
    char* filename1;
    char* filename2;
    int file_size;

    filename1 = argv[1];
    filename2 = argv[2];

    file_size = read_file(filename1, &buffer);
    char *newMem = malloc(file_size);

    for (int k = file_size - 1; k >= 0; k--) {
      newMem[file_size-k] = buffer[k];
    }
    write_file(filename2, newMem, file_size);
    free(buffer);
    return 0;
}