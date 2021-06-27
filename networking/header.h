#ifndef _NETWORKING_HEADER_INCLUDED_H_
#define _NETWORKING_HEADER_INCLUDED_H_

#include "status_codes.h"

const char *generate_headers(char *dest, HTTP_STATUS_CODES status, const char *body);

#endif // _NETWORKING_HEADER_INCLUDED_H_
