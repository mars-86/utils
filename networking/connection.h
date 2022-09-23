#ifndef _NETWORKING_CONNECTION_INCLUDED_H_
#define _NETWORKING_CONNECTION_INCLUDED_H_

#include "socket.h"

int connection_open(socket_t *sock, unsigned short port, int backlog);
int connection_accept(int socket, struct sockaddr *addr);
int connection_polling(int socket, const poll_config_t *config);
void connection_close(int socket);

#endif // _NETWORKING_CONNECTION_INCLUDED_H_
