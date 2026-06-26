/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/26 00:00:00 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			opt->ra++;
		else
			write(1, "ra\n", 3);
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
			opt->rb++;
		else
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack *a, t_stack *b, t_options *opt)
{
	ra(a, 0, opt);
	rb(b, 0, opt);
	if (opt->is_bench)
		opt->rr++;
	else
		write(1, "rr\n", 3);
}
