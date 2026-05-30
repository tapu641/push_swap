#include "push_swap.h"

void sa(t_stack *stack)
{
	int	tmp;

	if (!stack || (stack->size < 2))
		return ;
	tmp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = tmp;
	ft_printf("sa\n");
}

