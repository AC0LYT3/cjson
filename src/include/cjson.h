/*
 * cjson
 *
 * cjson.h
 * Matthew Todd Geiger
 * 2024-01-10
 */

#define CJSON_INSIDE 1
#define CJSON_OUTSIDE 2

#define CJSON_ERR char
#define CJSON_SUCCESS 0
#define CJSON_FAILURE 1

#define CJSON_TYPE_OBJECT   0
#define CJSON_TYPE_ARRAY    1
#define CJSON_TYPE_STRING   2
#define CJSON_TYPE_INT      3
#define CJSON_TYPE_BOOL     4
#define CJSON_TYPE_FLOAT    5

#ifndef __CJSON_H_
#define __CJSON_H_

#include <stdarg.h>

typedef struct cjson_data {
    const char *name;
    void *value;
    unsigned char type;
    struct cjson_data *parent;
} *PCJSON_DATA, CJSON_DATA;

// CJSON Object
typedef struct cjson {
    int fd; // Handle to file
    PCJSON_DATA entry; // Data tree entry
    char used; // This flag tells the handler that it can be freed
    struct cjson *next;
    struct cjson *prev;
} *PCJSON, CJSON;

// Create handle to json object
// Return Values
//  On success return handle to CJSON object
//  On failure return null
PCJSON cjson_init();

// Free json object
void cjson_free(PCJSON handle);

// Free all json objects
void cjson_free_all();

// Attach to file on file system
// Return Values
//  On success return CJSON_SUCCESS
//  On failure return CJSON_FAILURE
CJSON_ERR cjson_attach(PCJSON handle, const char *const filename);

// Read cjson data from attached file
CJSON_ERR cjson_read(PCJSON handle);

// Write cjson data to attached file
CJSON_ERR cjson_write(PCJSON handle);

// Parse raw json data
CJSON_ERR cjson_parse(PCJSON handle, const char *const buf);

// Find data in json object
// Return Values
//  On success return search result as string
//  On failure return null
// Example
//  ret = cjson_find(handle, "street", "houses", 3, "address")
char *cjson_find(PCJSON handle, ...);

// Copy json data from on handle to another
// Return Values
//  On success return CJSON_SUCCESS
//  On failure return CJSON_FAILURE
// Example
//  ret = cjson_add(src, dst, CJSON_INSIDE, "street", "houses")
CJSON_ERR cjson_copy(PCJSON src, PCJSON dst, unsigned int position, ...);

// Copy raw json into destination
// Return Values
//  On success return CJSON_SUCCESS
//  On failure return CJSON_FAILURE
// Example
//  ret = cjson_copy_raw(src, dst, CJSON_INSIDE, "\"Matt's House\":{\"address\":\"awesome\"}", "street", "houses")  
CJSON_ERR cjson_copy_raw(PCJSON src, PCJSON dst, const char *const raw, unsigned int position, ...);

// Get length of json data object or array
// Return Values
//  On success return length
//  On failure return CJSON_ERR
int cjson_len(PCJSON handle, ...);

// Return data type of json data
// Return Values
//  On success CJSON_TYPE_*
//  On failure CJSON_FAILURE
int cjson_type(PCJSON handle, ...);

#endif
