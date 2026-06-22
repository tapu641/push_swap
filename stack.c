#include "push_swap.h"

t_list	*ft_lstnew(int value, int index)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->value = value;
	res->index = index;
	res->next = NULL;
	return (res);
}

void	ft_lstadd_back(t_stack *stack, t_list *new)
{
	t_list	*current;

	if (!stack || !new)
		return ;
	stack->size++;
	if (!stack->top)
	{
		stack->top = new;
		return ;
	}
	current = stack->top;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

t_stack	*stack_new(void)
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
