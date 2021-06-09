#include "random.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

uint8_t get_random_uint8(void)
{
	srand(time(NULL));
	return rand() % UINT8_MAX;
}

uint16_t get_random_uint16(void)
{
	srand(time(NULL));
	return rand() % UINT16_MAX;
}

uint32_t get_random_uint32(void)
{
	srand(time(NULL));
	return rand() % UINT32_MAX;
}

uint64_t get_random_uint64(void)
{
	srand(time(NULL));
	return rand() % UINT64_MAX;
}

uint64_t get_random_unsigned(uint64_t offset)
{
	srand(time(NULL));
	return ((rand() % UINT64_MAX + offset) & 0xFFFFFFFFFFFFFFFF);
}
