#include "push_swap.h"

void sa(t_stack *stack, int flag)
{
    int tmp;

    if (!stack || stack->size < 2)
        return ;
    tmp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = tmp;
	if (flag)
    	write(1, "sa\n", 3);
}

void sb(t_stack *stack, int flag)
{
    int tmp;

    if (!stack || stack->size < 2)
        return ;
    tmp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = tmp;
	if (flag)
    	write(1, "sb\n", 3);
}

void ss(t_stack*a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
	t_list *tmp;

	if (!a || !b || !a->top)
		return ;
	tmp = pop_front(&(a->top));
	push_front(&(b->top), tmp);
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}

void pa(t_stack *a, t_stack *b)
{
    t_list *tmp;

    if (!a || !b || !b->top)
        return ;
    tmp = pop_front(&(b->top));
    push_front(&(a->top), tmp);
    b->size--;
    a->size++;
    write(1, "pa\n", 3);
}

void ra(t_stack *stack, int flag)
{
	t_list *tmp;
	t_list *last;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	tmp = pop_front(&(stack->top));
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	if (flag)
		write(1, "ra\n", 3);
}

void rra(t_stack *stack, int flag)
{
    t_list *tmp;
    t_list *prev;

    if (!stack || !stack->top || stack->size < 2)
        return ;
    prev = stack->top;
    while (prev->next->next != NULL)
        prev = prev->next;
    tmp = prev->next;
    prev->next = NULL;
    tmp->next = stack->top;
    stack->top = tmp;
	if (flag)
    	write(1, "rra\n", 4);
}

void rb(t_stack *stack, int flag)
{
	t_list *tmp;
	t_list *last;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	tmp = pop_front(&(stack->top));
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	if (flag)
		write(1, "rb\n", 3);
}

void rrb(t_stack *stack, int flag)
{
    t_list *tmp;
    t_list *prev;

    if (!stack || !stack->top || stack->size < 2)
        return ;
    prev = stack->top;
    while (prev->next->next != NULL)
        prev = prev->next;
    tmp = prev->next;
    prev->next = NULL;
    tmp->next = stack->top;
    stack->top = tmp;
	if (flag)
    	write(1, "rrb\n", 4);
}

void rr(t_stack *a, t_stack *b)
{
    ra(a, 0);
    rb(b, 0);
    write(1, "rr\n", 3);
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a, 0);
    rrb(b, 0);
    write(1, "rrr\n", 4);
}
