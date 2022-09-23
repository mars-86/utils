#include "connection.h"
#include "../os/error/error.h"

int connection_open(socket_t *sock, unsigned short port, int backlog)
{
    int sd;
	if ((sd = socket_create(TCP_SOCKET, sock)) < 0)
        return -1;

	if (socket_listen(sd, port, backlog, sock) < 0)
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

int connection_polling(int socket, const poll_config_t *config)
{
    socket_poll(socket, config);
}

void connection_close(int socket)
{
    socket_close(socket);
}
