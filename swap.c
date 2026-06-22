#include "push_swap.h"

void	sa(t_stack *stack, int flag, t_options *opt)
{
	int	tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
	if (flag)
	{
		if (opt->is_bench)
			opt->sa++;
		else
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack *stack, int flag, t_options *opt)
{
	int	tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
	if (flag)
	{
		if (opt->is_bench)
			opt->sb++;
		else
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b, t_options *opt)
{
	sa(a, 0, opt);
	sb(b, 0, opt);
	if (opt->is_bench)
		opt->ss++;
	else
		write(1, "ss\n", 3);
}
