#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/*
 * This program accepts 2 arguments in terminal in addition to the executable name,
 * <exec_name> <read_file_name> <write_file_name>. The read_file should be placed in
 * the working directory, else a file path will need to be specified.
 * The following code was referenced during the development process of this program:
 * https://github.com/irawoodring/pointer_perils
 *
 * Additional sources, less referred to sources have been cited in-line.
 *
 * Author: Derrik Fleming
 */

int main(int argc, char **argv) {
    // correct num arguments passed

    if(argc == 3) {
        char* pBuffer;              // pointer to buffer
        int readSize, writeSize;    // read/write sizes

        // argv[0] = exec
        // argv[1] = file to read
        // argv[2] = file to write
        readSize = read_file(argv[1], &pBuffer);
        writeSize = write_file(argv[2], pBuffer, readSize);

        // exception: read/write-reverse error
        if(readSize != writeSize) {
            // debug write error
            // printf("read:%d\n", readSize);
            // printf("write:%d\n", writeSize);

            fprintf(stderr, "Critical error occurred while writing! \nExiting . . .");
            exit(EXIT_FAILURE);
        }

        //free allocated mem
        free(pBuffer);
    }

    // update status to user
    printf("Success!\n%s, was written in reverse correctly.\n\n\n", argv[2]);

    return 0;
}