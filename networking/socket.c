#include "socket.h"
#include <stdio.h>
#include "../os/os.h"

#ifdef __WIN32
#include <winsock2.h>
#define _handle_err(msg) perror_win(msg)
#define _handle_err_and_clean(msg) _handle_err(msg), WSACleanup()
#define _close_socket(socket) closesocket(socket)
#else
#include <sys/socket.h>
#define _handle_err(msg) perror(msg)
#define _handle_err_and_clean(msg) _handle_err(msg)
#define _close_socket(socket) close(socket)
#endif // __WIN32

int open_connection(socket_t *sock)
{
#ifdef __WIN32
    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        _handle_err("WSAStartup failed");
        return -1;
    }
#endif // __WIN32

    int sock_s;
	if ((sock_s = socket(sock->domain, sock->type, sock->protocol)) == 0) {
        _handle_err_and_clean("create socket failed");
        return -1;
	}

    if (bind(sock_s, (struct sockaddr *)&sock->sa, sizeof(sock->sa)) < 0) {
        _handle_err_and_clean("bind socket");
        return -1;
    }

	if (listen(sock_s, sock->n_conn) < 0) {
		_handle_err_and_clean("listen failed");
        return -1;
	}

	if ((sock->descriptor = accept(sock_s, NULL, NULL)) == 0) {
        _handle_err_and_clean("accept failed");
        return -1;
	}
    _close_socket(sock_s);

	return 0;
}

int close_connection(socket_t *sock)
{
    int ret;
	if ((ret = closesocket(sock->descriptor)) < 0)
        _handle_err("close socket failed");
#ifdef __WIN32
    WSACleanup();
#endif // __WIN32
    return ret;
}
