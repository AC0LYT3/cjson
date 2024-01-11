/*
 * cjson
 *
 * macro.h
 * Matthew Todd Geiger
 * 2024-01-11
 */

#include <stdio.h>

#define PERR(str, ...) \
    fprintf(stderr, "ERROR [%s --> %s() --> %d] " str, __FILE__, __func__, __LINE__, ##__VA_ARGS__)

#ifdef _DEBUG
#define PERR_D(str, ...) PERR(str, ##__VA_ARGS__)
#else
#define PERR_D(str, ...)
#endif
