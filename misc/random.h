#ifndef _MISC_RANDOM_INCLUDED_H_
#define _MISC_RANDOM_INCLUDED_H_

#include <stdint.h>

uint8_t get_random_uint8(void);
uint16_t get_random_uint16(void);
uint32_t get_random_uint32(void);
uint64_t get_random_uint64(void);
uint64_t get_random_unsigned(uint64_t offset);

#endif // _MISC_RANDOM_INCLUDED_H_
