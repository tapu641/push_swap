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
			opt->rra++;
		else
			write(1, "rra\n", 4);
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
			opt->rrb++;
		else
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *a, t_stack *b, t_options *opt)
{
	rra(a, 0, opt);
	rrb(b, 0, opt);
	if (opt->is_bench)
		opt->rrr++;
	else
		write(1, "rrr\n", 4);
}
