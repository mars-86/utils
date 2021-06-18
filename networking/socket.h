#ifndef _NETWORKING_SOCKET_INCLUDED_H_
#define _NETWORKING_SOCKET_INCLUDED_H_

// #include <sys/socket.h>
#include <winsock2.h>

enum {
	TCP_SOCKET = SOCK_STREAM,
	UDP_SOCKET = SOCK_DGRAM,
	RAW_SOCKET = SOCK_RAW
} typedef socket_type_t;

struct {
	char name[32];
	int descriptor;
	int domain;
	socket_type_t type;
	int protocol;
	int n_conn;
	struct sockaddr_in sa;
} typedef socket_t;

int open_connection(socket_t *socket);
int close_connection(socket_t *socket);

#endif // _NETWORKING_SOCKET_INCLUDED_H_
