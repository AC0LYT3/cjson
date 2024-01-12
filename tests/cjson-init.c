/*
 * cjson tests
 *
 * cjson-init.c
 * Matthew Todd Geiger
 * Started: 2024-01-11
 */

#include <stdlib.h>

#include "cjson.h"
#include "macro.h"

void usage(const char * const argv0) {
    printf("%s number_of_handles\n", argv0);
    exit(EXIT_FAILURE);
}

int main(int argc, char ** argv) {
    if(argc != 2)
       usage(argv[0]); 

    /*
    for (int i = 0; i < atoi(argv[1]); i++) {
        PCJSON handle = cjson_init();
        cjson_free(handle);
    }*/

    for(int i = 0; i < atoi(argv[1]); i++) {
        (void*)cjson_init();
    }

    cjson_free_all();
}
