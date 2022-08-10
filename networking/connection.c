#include "connection.h"
#include "../os/error/error.h"

int connection_open(socket_t *sock)
{
    int sd;
	if ((sd = socket_create(TCP_SOCKET, sock)) < 0)
        return -1;

	if (socket_listen(sd, 8080, 5, sock) < 0)
        return -1;

	return sd;
}

int connection_accept(int socket, struct sockaddr *addr)
{
    int sd;
    if ((sd = socket_accept(socket, addr)) < 0)
        return -1;
    return sd;
}

int connection_polling()
{


}

int connection_close(int socket)
{
    int ret;
//	if ((ret = closesocket(socket)) < 0)
//        _handle_err("close socket failed");
#ifdef __WIN32
    WSACleanup();
#endif // __WIN32
    return ret;
}
