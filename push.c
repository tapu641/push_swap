#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, t_options *opt)
{
	t_list	*tmp;

	if (!a || !b || !b->top)
		return ;
	tmp = pop_front(&(b->top));
	push_front(&(a->top), tmp);
	b->size--;
	a->size++;
	if (opt->is_bench)
	{
		write(1, "pa\n", 3);
		opt->pa++;
	}
}

void	pb(t_stack *a, t_stack *b, t_options *opt)
{
	t_list	*tmp;

	if (!a || !b || !a->top)
		return ;
	tmp = pop_front(&(a->top));
	push_front(&(b->top), tmp);
	a->size--;
	b->size++;
	if (opt->is_bench)
	{
		write(1, "pb\n", 3);
		opt->pb++;
	}
}

