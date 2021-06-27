#include "stack.h"

void delete_stack(stack_t **stack)
{
    (*stack)->pop_all();
    free(*stack);
}
