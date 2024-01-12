/*
 * cjson
 *
 * mem.c
 * Matthew Todd Geiger
 * Started: 2024-01-11
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "mem.h"
#include "macro.h"

void *ec_malloc(uint64_t size) {
    void *buf = malloc(size);
    if(buf == (void*)NULL) {
        PERR_D("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    
    return buf;
}

void *ec_realloc(void *buf, uint64_t size) {
    void *ret = realloc(buf, size);
    if(ret == (void*)NULL) {
        PERR_D("Failed to reallocate memory");
        exit(EXIT_FAILURE);
    }

    return ret;
}
