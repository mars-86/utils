#ifndef _OS_TYPES_INCLUDED_H_
#define _OS_TYPES_INCLUDED_H_

#ifdef _USE_STDINT_H
  
#ifdef HAVE_STDINT_H
  #include <stdint.h>
#else
  #error intX_t definitions missing
#endif

#else

#ifndef int8_t
// typedef char int8_t;
#endif
typedef short int16_t;
typedef int int32_t;
// typedef long long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
// typedef unsigned long long int uint64_t;

#endif

#endif // _OS_TYPES_INCLUDED_H