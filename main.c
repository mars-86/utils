#include "networking/socket.h"
#include "networking/header.h"
#include "os/os.h"
#include "view/table.h"
#include <stdio.h>

int main(void)
{
    table_t *tab;
    const char *head[] = {"col1", "col2", "col3"};
    table_create(&tab, head, NULL);
    table_print(tab);
    table_cleanup(&tab);

    /*
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

    char buff[512], buff_s[512];
    int bytes_recv, bytes_send;
    do {
        bytes_recv = 1;
        bytes_recv = recv(sock.descriptor, buff, 128, 0);
        if (bytes_recv > 0) {
            printf("%s\n", buff);
            generate_headers(buff_s, OK, "<h1>We've got a badass over here!</h1>");
            bytes_send = send(sock.descriptor, buff_s, strlen(buff_s), 0);
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
    */
    return 0;
}
