#include "push_swap.h"

t_stack *stack_new(void)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
	}
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

void    stack_free(t_stack *stack)
{
    t_list *current;
    t_list *next;

    if (!stack)
        return ;
    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
