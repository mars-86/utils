#include "allocator.h"
#include <stdlib.h>

#define _DEBUG_
#ifdef _DEBUG_

#ifdef _DEBUG_DYNAMIC_

// fix: dynamic allocation -> context error on free memaddr_t
struct memaddr {
    void *addr;
    size_t size;
    struct memaddr *next;
    struct memaddr *prev;
};

typedef struct memaddr memaddr_t;

struct addrs {
    memaddr_t *begin;
};

typedef struct addrs addrs_t;

static addrs_t *addrs_ls = NULL;

void init_addrs_list(void)
{
    addrs_ls = (addrs_t *)malloc(sizeof(addrs_t));
    addrs_ls->begin = NULL;
}

memaddr_t *alloc_addr(void *addr, size_t size)
{
    memaddr_t *new_addr = (memaddr_t *)malloc(size);
    new_addr->addr = addr;
    new_addr->size = size;
    new_addr->next = NULL;
    new_addr->prev = NULL;

    return new_addr;
}

void free_addr(memaddr_t *addr)
{
    printf("%p\n", addr);
    if (addr != NULL) {
        free(addr->addr), addr->addr = NULL;
        free(addr);
    }
    addr = NULL;
    printf("%p\n", addr->addr);
}

void add_addr(void *addr, size_t size)
{
    memaddr_t *new_addr = alloc_addr(addr, size);
    if (addrs_ls->begin == NULL) {
        addrs_ls->begin = new_addr;
    } else {
        memaddr_t *paddr;
        for (paddr = addrs_ls->begin; paddr != NULL; paddr = paddr->next) {
            if (paddr->next == NULL) {
                new_addr->prev = paddr;
                paddr->next = new_addr;
                break;
            }
        }
    }
}

void remove_addr(void *addr)
{
    memaddr_t *paddr;
    for (paddr = addrs_ls->begin; paddr != NULL; paddr = paddr->next) {
        if (paddr->addr == addr) {
            if (paddr->prev == NULL) {
                addrs_ls->begin = paddr->next;
            } else {
                paddr->prev->next = paddr->next;
                paddr->prev = NULL;
            }
            paddr->next = NULL;
            break;
        }
    }
    free(paddr);
    free_addr(paddr);
}

void _list_addrs(void)
{
    memaddr_t *paddr;
    for (paddr = addrs_ls->begin; paddr != NULL; paddr = paddr->next) {
        printf("addr: %p\nsize: %u\n", paddr->addr, paddr->size);
    }
}

#else

#ifndef DEBUG_MEM_ADDR_MAX

#define DEBUG_MEM_ADDR_MAX 256

#endif // DEBUG_MEM_ADDR_MAX

struct memaddr {
    void *addr;
    size_t size;
    int free;
};

typedef struct memaddr memaddr_t;

static memaddr_t addrs_ls[DEBUG_MEM_ADDR_MAX];
static int addrs_ls_init = 0;

void init_addrs_list(void)
{
    int i;
    for (i = 0; i < DEBUG_MEM_ADDR_MAX; ++i)
        addrs_ls[i] = (memaddr_t){NULL, 0, 1};
    addrs_ls_init = 1;
}

memaddr_t alloc_addr(void *addr, size_t size)
{
    return (memaddr_t){addr, size, 0};
}

void free_addr(memaddr_t *memory)
{
    free(memory->addr);
    memory->addr = NULL;
    memory->size = 0;
    memory->free = 1;
}

// refac: use global index
void add_addr(void *addr, size_t size)
{
    int i;
    for (i = 0; i < DEBUG_MEM_ADDR_MAX; ++i) {
        if (addrs_ls[i].free)
            break;
    }
    addrs_ls[i] = alloc_addr(addr, size);
}

void remove_addr(void *addr)
{
    int i;
    for (i = 0; i < DEBUG_MEM_ADDR_MAX; ++i) {
        if (addrs_ls[i].addr == addr)
            break;
    }
    free_addr(&addrs_ls[i]);
}

void _list_addrs(void)
{
    int i;
    for (i = 0; i < DEBUG_MEM_ADDR_MAX; ++i) {
        if (!addrs_ls[i].free)
            printf("addr: %p\nsize: %u\n", addrs_ls[i].addr, addrs_ls[i].size);
    }
}

#endif // _DEBUG_DYNAMIC_


#endif

void *memalloc(size_t size)
{
    void *mem = malloc(size);
#ifdef _DEBUG_
    if (addrs_ls == NULL || !addrs_ls_init)
        init_addrs_list();
    add_addr(mem, size);
#endif // _DEBUG_
    return mem;
}

void dealloc(void *memory)
{
#ifdef _DEBUG_
    remove_addr(memory);
#else
    free(memory);
#endif
}

void list_addrs(void)
{
#ifdef _DEBUG_
    _list_addrs();
#endif
}
