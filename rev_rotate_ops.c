#include "push_swap.h"

void	rra(t_stack *stack, int flag, t_options *opt)
{
	t_list	*tmp;
	t_list	*prev;

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
	{
		if (opt->is_bench)
		{
			write(1, "rra\n", 3);
			opt->rra++;
		}
	}
}

void	rrb(t_stack *stack, int flag, t_options *opt)
{
	t_list	*tmp;
	t_list	*prev;

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
	{
		if (opt->is_bench)
		{
			write(1, "rrb\n", 3);
			opt->rrb++;
		}
	}
}

void	rrr(t_stack *a, t_stack *b, t_options *opt)
{
	rra(a, 0, opt);
	rrb(b, 0, opt);
	if (opt->is_bench)
	{
		write(1, "rrr\n", 3);
		opt->rrr++;
	}
}
