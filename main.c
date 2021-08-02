#include "networking/socket.h"
#include "networking/header.h"
#include "os/os.h"
#include <stdio.h>
#include "template_v2/stack.h"
#include "template_v2/queue.h"

typedef char * char_ptr8;

new_stack_type(int);
new_stack_type(char_ptr8);

new_queue_type(int);

void int_stack_print(int val, int index, int_stack_t **stack) {
    printf("%d ", val);
}

void char_ptr8_stack_print(char *val, int index, int_stack_t **stack) {
    printf("%s", val);
}

void int_queue_print(int val, int index, int_queue_t **queue) {
    printf("%d ", val);
}

int main(void)
{
    /* STACK */
    int_stack_t stck;
    new_stack(my_stack, int);
    new_stack(my_stack2, int);
    int_stack_push(&my_stack, 4);
    int_stack_push(&my_stack, 10);
    int_stack_push(&my_stack, 13);
    int_stack_push(&my_stack, 7);
    int_stack_for_each(&my_stack, int_stack_print);
    printf("\n");
    printf("%d\n", int_stack_length(my_stack));
    int_stack_push(&my_stack2, 33);
    int_stack_push(&my_stack2, 4252);
    int_stack_push(&my_stack2, 67);
    int_stack_push(&my_stack2, 79);
    int_stack_for_each(&my_stack2, int_stack_print);
    printf("\n");
    printf("%d\n", int_stack_length(my_stack2));
    int_stack_pop_all(&my_stack);
    int_stack_for_each(&my_stack, int_stack_print);
    printf("\n");
    printf("%d\n", int_stack_length(my_stack));
    int_stack_delete(&my_stack);
    int_stack_delete(&my_stack2);

    int_stack_push((&stck), 79);
    int_stack_for_each((&stck), int_stack_print);
    printf("\n");

    new_stack(charp_stack, char_ptr8);
    char_ptr8_stack_push((&charp_stack), "Hello ");
    char_ptr8_stack_push((&charp_stack), "World");
    char_ptr8_stack_push((&charp_stack), "!\n");
    char_ptr8_stack_for_each(&charp_stack, char_ptr8_stack_print);

    char_ptr8_stack_delete(&charp_stack);

    /* QUEUE */
    new_queue(my_queue, int);
    int_queue_insert(&my_queue, 9);
    int_queue_insert(&my_queue, 99);
    int_queue_insert(&my_queue, 999);
    int_queue_for_each(&my_queue, int_queue_print);
    printf("\n");
    int_queue_delete(&my_queue);

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
