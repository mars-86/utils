#include "networking/socket.h"
#include "networking/header.h"
#include "networking/connection.h"
#include "os/os.h"
#include "stream/logger.h"
#include <stdio.h>

void handle_incomming_data(int sock, struct sockaddr *addr)
{
    int bytes_recv, bytes_send;
    char buff[512], buff_s[512];
    bytes_recv = 1;
    bytes_recv = recv(sock, buff, 128, 0);
    if (bytes_recv > 0) {
        printf("%s\n", buff);
        generate_headers(buff_s, OK, "<h1>We've got a badass over here!</h1>");
        bytes_send = send(sock, buff_s, strlen(buff_s), 0);
        if (bytes_send == -1)
            perror_win("send");
        else
            printf("%d bytes sent\n", bytes_send);
    }
    else if (!bytes_recv) {
        printf("Connection closed\n");
        closesocket(sock);
    }
    else
        perror_win("recv");
}

int main(void) {
    int sd, accept_sd;

    if ((sd = connection_open(NULL)) < 0) {
        fprintf(stderr, "Error on creating a connection");
        return -1;
    }

    log_info("Listening for connections..\n");

    poll_config_t poll_conf;

    poll_conf.nfds = 32;
    poll_conf.timeout = 1000;
    poll_conf.handler = &handle_incomming_data;
    poll_conf.events = POLLIN;

    socket_poll(sd, &poll_conf);

    return 0;
    if ((accept_sd = connection_accept(sd, NULL)) < 0) {
        fprintf(stderr, "Cannot start accepting connections");
        return -1;
    }

    char buff[512], buff_s[512];
    int bytes_recv, bytes_send;
    do {
        bytes_recv = 1;
        bytes_recv = recv(accept_sd, buff, 128, 0);
        if (bytes_recv > 0) {
            printf("%s\n", buff);
            generate_headers(buff_s, OK, "<h1>We've got a badass over here!</h1>");
            bytes_send = send(accept_sd, buff_s, strlen(buff_s), 0);
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

    connection_close(accept_sd);

    return 0;
}
