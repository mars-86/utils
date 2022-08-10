#ifndef _NETWORKING_HTTP_INCLUDED_H_
#define _NETWORKING_HTTP_INCLUDED_H_

#include "socket.h"

typedef struct http_server {
    socket_t *sock;
} http_server_t;

int server_init(http_server_t *server);
int server_listen(http_server_t *server, unsigned short port);

#endif // _NETWORKING_HTTP_INCLUDED_H_
