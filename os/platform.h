#ifndef _OS_PLATFORM_INCLUDED_H_
#define _OS_PLATFORM_INCLUDED_H_

#include "types.h"

typedef struct _ContainerSize {
    uint16_t cs_row;
    uint16_t cs_col;
    uint16_t cs_row_max;
    uint16_t cs_col_max;
} ContainerSize;

#endif // _OS_PLATFORM_INCLUDED_H_