#ifndef _NETWORKING_HTTP_INCLUDED_H_
#define _NETWORKING_HTTP_INCLUDED_H_

#include "socket.h"

typedef struct http_server_config {
    int backlog;
    poll_config_t *poll;
} http_server_config_t;

typedef struct http_server {
    socket_t *sock;
    http_server_config_t *config;
} http_server_t;

http_server_t *server_init(const http_server_config_t *config);
int server_listen(const http_server_t *server, unsigned short port);
void server_destroy(const http_server_t *server);

#endif // _NETWORKING_HTTP_INCLUDED_H_
