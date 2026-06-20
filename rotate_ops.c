#include "push_swap.h"

void	ra(t_stack *stack, int flag, t_options *opt)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	tmp = pop_front(&(stack->top));
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	if (flag)
	{
		if (opt->is_bench)
		{
			write(1, "ra\n", 3);
			opt->ra++;
		}
	}
}

void	rb(t_stack *stack, int flag, t_options *opt)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	tmp = pop_front(&(stack->top));
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	if (flag)
	{
		if (opt->is_bench)
		{
			write(1, "rb\n", 3);
			opt->rb++;
		}
	}
}

void	rr(t_stack *a, t_stack *b, t_options *opt)
{
	ra(a, 0, opt);
	rb(b, 0, opt);
	if (opt->is_bench)
	{
		write(1, "rr\n", 3);
		opt->rr++;
	}
}
