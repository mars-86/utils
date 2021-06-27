#include "networking/socket.h"
#include "os/os.h"
#include <stdio.h>

int main(void)
{
    socket_t sock;
    sock.domain = AF_INET;
    sock.type = TCP_SOCKET;
    sock.protocol = 0;
    sock.n_conn = 5;
    sock.sa.sin_family = AF_INET;
    sock.sa.sin_port = htons(8080);
    sock.sa.sin_addr.s_addr = INADDR_ANY;

    if (!open_connection(&sock))
        printf("Listening for connections\n");

    char buff[512];
    char res[] =
                "HTTP/1.1 200 OK\r\n\r\n"
                "<h1>We've got a badass over here!</h1>";

    int bytes_recv, bytes_send;
    do {
        bytes_recv = 1;
        bytes_recv = recv(sock.descriptor, buff, 128, 0);
        if (bytes_recv > 0) {
            printf("%s\n", buff);
            bytes_send = send(sock.descriptor, res, strlen(res), 0);
            if (bytes_send == -1)
                perror_win("send");
            else
                printf("%d bytes sent\n", bytes_send);
        }
        else if (!bytes_recv)
            printf("Connection closed\n");
        else
            perror_win("recv");
    } while (bytes_recv > 0);

    close_connection(&sock);

    return 0;
}
