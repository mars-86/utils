#ifndef _NETWORKING_SOCKET_INCLUDED_H_
#define _NETWORKING_SOCKET_INCLUDED_H_

#ifdef __WIN32
#include <winsock2.h>
#ifdef _MSC_VER
#pragma comment (lib, "Ws2_32.lib")
#endif // _MSC_VER
#else
#include <sys/socket.h>
#endif // __WIN32

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

void perror_m(const char *msg);
int open_connection(socket_t *socket);
int close_connection(socket_t *socket);

#endif // _NETWORKING_SOCKET_INCLUDED_H_
