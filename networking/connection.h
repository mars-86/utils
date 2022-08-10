#ifndef _NETWORKING_CONNECTION_INCLUDED_H_
#define _NETWORKING_CONNECTION_INCLUDED_H_

#include "socket.h"

int connection_open(socket_t *sock);
int connection_accept(int socket, struct sockaddr *addr);
int connection_polling();
int connection_close(int socket);

#endif // _NETWORKING_CONNECTION_INCLUDED_H_
