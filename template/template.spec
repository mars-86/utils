void foo(list_t **l)
{
    (*l)->insert(70);
}

long sum(long n1, long n2)
{
    return n1 + n2;
}

struct my_int_types {
    int x;
    int y;
    int z;
} typedef int_types_t;

void custom_printf(int elem, int index, list_t **list)
{
    printf("%d: %d\n", index, elem);
}

void custom_printf_s(int elem, int index, stack_t **list)
{
    printf("%d: %d\n", index, elem);
}

void custom_printf_q(int elem, int index, queue_t **list)
{
    printf("%d: %d\n", index, elem);
}

void custom_printf2(long elem, int index, list_t **list)
{
    printf("%d: %ld\n", index, elem);
}

void custom_printf3(char *elem, int index, list_t **list)
{
    printf("%d: %s\n", index, elem);
}

void pow2(int_types_t *elem, int index, list_t **list)
{
    elem->x *= elem->x;
    elem->y *= elem->y;
    elem->z *= elem->z;
}

void custom_printf4(int_types_t *elem, int index, list_t **list)
{
    printf("%d: %d, %d, %d\n", index, elem->x, elem->y, elem->z);
}

int test(void)
{
    printf("******** QUEUE *********\n");
    queue_t *queue;
    new_queue(queue, int);
    queue->insert(67);
    queue->insert(45);
    queue->insert(83);
    queue->for_each(custom_printf_q);
    queue->remove();
    queue->for_each(custom_printf_q);
    queue->insert(99);
    queue->for_each(custom_printf_q);
    queue->remove();
    queue->for_each(custom_printf_q);
    queue->remove_all();
    queue->for_each(custom_printf_q);

    delete_queue(&queue);

    printf("******** STACK *********\n");
    stack_t *stack;
    new_stack(stack, int);
    stack->push(33);
    stack->push(35);
    stack->push(37);
    stack->for_each(custom_printf_s);
    stack->pop();
    stack->for_each(custom_printf_s);
    stack->push(39);
    stack->for_each(custom_printf_s);
    stack->pop_all();
    stack->for_each(custom_printf_s);
    delete_stack(&stack);

    printf("******** LIST *********\n");
    list_t *list1, *list2, *list3;
    new_list(list1, int);

    list1->insert(3);
    list1->insert(5);
    list1->insert(7);
    printf("length: %d\n", list1->length());
    list1->for_each(custom_printf);
    list1->remove_all();
    printf("length: %d\n", list1->length());
    list1->for_each(custom_printf);
    foo(&list1);
    list1->for_each(custom_printf);
    printf("length: %d\n", list1->length());
    list1->insert(3);
    list1->insert(5);
    list1->insert(7);
    list1->for_each(custom_printf);
    list1->remove_last();
    list1->for_each(custom_printf);
    list1->remove_last();
    list1->for_each(custom_printf);
    list1->remove_last();
    list1->for_each(custom_printf);
    list1->remove_last();
    list1->remove_last();
    list1->insert(15);
    list1->for_each(custom_printf);
    list1->remove_last();
    list1->remove_last();
    new_list(list2, long);

    list2->insert(sum(3333, 3333));
    list2->insert(sum(5555, 5555));
    list2->for_each(custom_printf2);
    list2->remove_last();
    list2->remove_last();

    new_list(list3, char *);
    list3->insert("Hello,");
    list3->insert("world");
    printf("length: %d\n", list3->length());
    list3->insert("!");

    list3->for_each(custom_printf3);

    delete_list(&list1);
    delete_list(&list2);
    delete_list(&list3);

    printf("******** LIST CUSTOM TYPE *********\n");
    list_t *list4;
    new_list(list4, int_types_t *);

    int_types_t i1 = {1, 2, 3};
    int_types_t i2 = {4, 5, 6};
    list4->insert(&i1);
    list4->insert(&i2);
    list4->for_each(custom_printf4);
    list4->for_each(pow2);
    list4->for_each(custom_printf4);
    list4->remove_last();
    list4->remove_last();

    delete_list(&list4);
}