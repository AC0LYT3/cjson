/*
 * cjson
 *
 * mem.h
 * Matthew Todd Geiger
 * Started: 2024-01-11
 */

#include <stdint.h>

#ifndef __MEM_H_
#define __MEM_H_

void *ec_malloc(uint64_t size);
void *ec_realloc(void *buf, uint64_t size);

#endif
