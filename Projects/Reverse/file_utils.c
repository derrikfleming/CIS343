#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "file_utils.h"

/*
 * The code that the instructor provided in the following repository was referred to
 * several times during the development of both of the following methods,
 * https://github.com/irawoodring/pointer_perils
 *
 * Author: Derrik Fleming
 */
int read_file( char* filename, char **buffer) {
    // attempt open file
    FILE* readFile = fopen(filename, "r");

    // exception: file not open
    if(readFile == NULL) {
        // instructor supplied next line
        fprintf(stderr, "Could not open the file: %s\nExiting. . . ", filename);

        exit(EXIT_FAILURE);
    }

    printf("File is open . . .\n\n");

    // instructor supplied find file size routine
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    // position
    char cursor;

    // allocate buffer size equal to size of file
    *buffer = malloc(size * sizeof(char));

    printf("Reading file %s. . .\n", filename);

    // fgetc found at https://www.tutorialspoint.com/cprogramming/c_file_io.htm
    for(int i = 0; i < size; i++) {
        cursor = fgetc(readFile);
        // debug:
        // printf("cursor: %c", cursor);
        (*buffer)[i] = cursor;
        // debug:
        // printf("(*buffer)[i]: %c", (*buffer)[i]);
    }
    fclose(readFile);

    return size;
}
int write_file( char* filename, char *buffer, int size) {
    // attempt open file
    FILE* writeFile = fopen(filename, "w");

    // exception: file not open
    if(!writeFile) {
        // instructor supplied next line
        fprintf(stderr, "Could not open the file: %s\nExiting . . . ", filename);

        exit(EXIT_FAILURE);
    }

    printf("Writing file %s . . . ", filename);

    // fputc found at https://www.tutorialspoint.com/cprogramming/c_file_io.htm
    for(int i = size-1; i >= 0; i--) {
        fputc(buffer[i], writeFile);
    }
    // graceful close
    fclose(writeFile);

    // get size of written file
    struct stat st;
    stat(filename, &st);
    int writeSize = st.st_size;

    return writeSize;
    //TO-DO: return number bytes written to file
    //or return completion val
}