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

typedef enum socket_type {
	TCP_SOCKET = SOCK_STREAM,
	UDP_SOCKET = SOCK_DGRAM,
	RAW_SOCKET = SOCK_RAW
} socket_type_t;

typedef struct socket {
	char name[32];
	int descriptor;
	int domain;
	socket_type_t type;
	int protocol;
	int backlog;
	struct sockaddr_in sa;
} socket_t;

typedef struct poll_config {
	int nfds;
	int timeout;
	void (*handler)(int socket, struct sockaddr *addr);
	int events;
	struct sockaddr_in sa;
} poll_config_t;

void perror_m(const char *msg);
int socket_create(socket_type_t type, socket_t *sock);
int socket_listen(int socket, unsigned short port, int backlog, socket_t *sock);
int socket_accept(int socket, struct sockaddr *addr);
int socket_poll(int listen_sock, poll_config_t *poll);

#endif // _NETWORKING_SOCKET_INCLUDED_H_
