typedef char * char_ptr8;

new_stack_type(int);
new_stack_type(char_ptr8);

new_queue_type(int);

new_list_type(int);

void int_stack_print(int val, int index, int_stack_t **stack) {
    printf("%d ", val);
}

void char_ptr8_stack_print(char *val, int index, int_stack_t **stack) {
    printf("%s", val);
}

void int_queue_print(int val, int index, int_queue_t **queue) {
    printf("%d ", val);
}

void int_list_print(int val, int index, int_list_t **list) {
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

    /* LIST */
    new_list(my_list, int);
    int_list_insert(&my_list, 80);
    int_list_insert(&my_list, 81);
    int_list_insert(&my_list, 82);
    int_list_insert(&my_list, 83);
    int_list_for_each(&my_list, int_list_print);
    printf("\n");
    int_list_remove_last(&my_list);
    int_list_for_each(&my_list, int_list_print);
    printf("\n");
    printf("TAIL: %d\n", int_list_tail(my_list));
    int_list_remove_last(&my_list);
    int_list_for_each(&my_list, int_list_print);
    printf("\n");
    printf("HEAD: %d\n", int_list_head(my_list));
    int_list_delete(&my_list);

	return 0;
}