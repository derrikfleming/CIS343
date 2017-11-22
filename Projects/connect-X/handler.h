//
// Created by Derrik Fleming on 2/26/17.
//

#ifndef CONNECT_X_HANDLER_H
#define CONNECT_X_HANDLER_H

#include <argp.h>

struct arguments {
    int width;
    int height;
    int connect;
    char *load;
    char *save;
};

// Function to setup values once they are parsed.
error_t parse_opt(int key, char* arg, struct argp_state *state);

// Function to begin the parsing process.
void setup(int argc, char** argv, struct arguments *pArgs);

#endif //CONNECT_X_HANDLER_H
