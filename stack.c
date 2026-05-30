#include "push_swap.h"

t_stack *stack_new(int max)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
    {
		write(2, "Error\n", 6);
		exit(1);
	}
    stack->data = malloc(sizeof(int) * max);
	if (!stack->data)
    {
		free(stack);
		write(2, "Error\n", 6);
		exit(1);
	}
    stack->size = 0;
    stack->max = max;
    return (stack);
}

void	stack_free(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->data)
		free(stack->data);
	free(stack);
}
