#ifndef _MEMORY_ALLOCATOR_INCLUDED_H_
#define _MEMORY_ALLOCATOR_INCLUDED_H_

#include<stdio.h>

void *memalloc(size_t size);
void dealloc(void *memory);
void list_addrs(void);

#endif // _MEMORY_ALLOCATOR_INCLUDED_H_
