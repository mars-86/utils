#include "header.h"
#include <stdio.h>
#include <string.h>

const char *generate_headers(const char *dest, HTTP_STATUS_CODES status, const char *body)
{
    sprintf(dest,
            "HTTP/1.1 %ull OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: %d\r\n\r\n"
            "%s", status, strlen(body), body);
    return dest;
}
