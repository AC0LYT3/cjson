/*
 * cjson
 *
 * cjson.c
 * Matthew Todd Geiger
 * Started: 2024-01-10
 */

#include <stdlib.h>
#include <string.h>

#include "cjson.h"
#include "macro.h"
#include "mem.h"

#define HANDLE_ARRAY_CHUNK_SIZE 32

static int handle_array_size = HANDLE_ARRAY_CHUNK_SIZE;
static PCJSON handle_list = (PCJSON)(NULL);

PCJSON cjson_init() {
    // Check if handle list has been created
    if (handle_list == (PCJSON)(NULL)) {
        handle_list = (PCJSON)ec_malloc(sizeof(CJSON) * HANDLE_ARRAY_CHUNK_SIZE);
        memset(handle_list, 0, sizeof(CJSON) * HANDLE_ARRAY_CHUNK_SIZE);
    }

    // Find available memory segment
    int index_position = 0;
    for (int i = 0; i < handle_array_size; i++) {
        index_position = i;

        // Break when unused segment is found
        if (!handle_list[i].used) {
            PDEBUG_D("Free handle found at index %d", i);
            break;
        }
    }

    // Expand buffer if needed
    // the for loop will exit naturally on a used buffer
    // if a resize is required
    if (handle_list[index_position].used) {
        PDEBUG_D("Resizing handle buffer");
        
        int old_size = handle_array_size;

        handle_array_size += HANDLE_ARRAY_CHUNK_SIZE;
        handle_list = (PCJSON)ec_realloc(handle_list, handle_array_size * sizeof(CJSON));

        PDEBUG_D("Zeroing %p to %p", (void*)&handle_list[old_size],
                    (void*)(&handle_list[handle_array_size-1]-&handle_list[old_size]));

        memset(handle_list + old_size, 0, (handle_list+handle_array_size-1)-(handle_list+old_size));

        index_position++;
    }

    // Initialize handle
    handle_list[index_position].used = 1;

    PDEBUG_D("Returning address %p + %d [%p]", (void*)handle_list, index_position, (void*)(handle_list + index_position));

    // Return pointer to initialized data structure
    return handle_list + index_position;
}

/*PCJSON cjson_init() {
    PCJSON ret = (PCJSON)ec_malloc(sizeof(CJSON));
    ret->entry = (PCJSON_DATA)NULL;
    return ret;
}

void cjson_free(PCJSON handle) {
    free(handle);
}*/

void cjson_free(PCJSON handle) {
    handle->used = 0;
}

void cjson_free_all() {
    if(handle_list != (PCJSON)NULL)
        free(handle_list);
}
