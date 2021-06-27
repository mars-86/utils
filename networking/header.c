#include "header.h"

const char *generate_headers(const char *dest, HTTP_STATUS_CODES status, const char *body)
{
    sprintf(dest,
            "HTTP/1.1 %d OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: %d\r\n\r\n"
            "%s", status, strlen(body), body);
    return dest;
}
