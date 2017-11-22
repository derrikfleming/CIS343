#include <stdlib.h>
#include "handler.h"

// Title
const char *argp_program_version = "ConnectX Release: 1.0";

// Developer contact information
const char *argp_program_bug_address = "fleminde@mail.gvsu.edu";

// Documentation string.
char doc[] = "A scalable Connect4-like game; using pointers, allocated memory, and parsing via argp.";

// Description of the required arguments we accept.
char args_doc[] = "";

// This option struct is for any optional arguments.
struct argp_option options[] = {
        {"width",	'w',	"WIDTH",	0,	"The width of the game board." },
        {"height",	'h',	"HEIGHT",	0,	"The height of the game board." },
        {"square",	's',	"SQUARE",	0,	"Square game board." },
        {"connect",	'c',	"CONNECT", 	0, 	"Win with a series of." },
        {"load",	'l',	"LOAD", 	0, 	"Load previous game." },
        { 0 }
};

struct argp argp = { options, parse_opt, args_doc, doc };
struct arguments arguments;

error_t parse_opt(int key, char* arg, struct argp_state *state){
    struct arguments *arguments = state->input;
    switch(key){
        case 'w':
            arguments->width = atoi(arg);
            break;
        case 'h':
            arguments->height = atoi(arg);
            break;
        case 's':
            arguments->width = atoi(arg);
            arguments->height = atoi(arg);
            break;
        case 'c':
            arguments->connect = atoi(arg);
            break;
        case 'l':
            arguments->load = arg;
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}


void setup(int argc, char** argv, struct arguments *pArgs){
    char* load_file = NULL;

    // Call argp to do its thing.
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    // Return values are in the arguments struct.  Pull
    // them out if they are there.
    *pArgs = arguments;
} 