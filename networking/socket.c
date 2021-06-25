#include "socket.h"
// #include <sys/socket.h>
#include <winsock2.h>
#include <stdio.h>

void perror_m(const char *msg)
{
    WCHAR *buff;
    FormatMessageW(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL, WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&buff, 0, NULL);
    fprintf(stderr, "%s: %S\n", msg, buff);
    LocalFree(buff);
}

int open_connection(socket_t *sock)
{
    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        perror_m("WSAStartup failed");
        return -1;
    }

    int sock_s;
	if ((sock_s = socket(sock->domain, sock->type, sock->protocol)) == 0) {
        perror_m("create socket failed");
        return -1;
	}

    if (bind(sock_s, (struct sockaddr *)&sock->sa, sizeof(sock->sa)) < 0) {
        perror_m("bind socket");
        return -1;
    }

	if (listen(sock_s, sock->n_conn) < 0) {
		perror_m("listen failed");
        return -1;
	}

	if ((sock->descriptor = accept(sock_s, NULL, NULL)) == 0) {
        perror_m("accept failed");
        return -1;
	}
    closesocket(sock_s);

	return 0;
}

int close_connection(socket_t *sock)
{
    int ret;
	if ((ret = closesocket(sock->descriptor)) < 0)
        perror_m("close socket failed");
    WSACleanup();
    return ret;
}
