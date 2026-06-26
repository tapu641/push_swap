/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/26 00:00:00 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks(t_stack *a, t_stack *b, t_options *opt)
{
	int	chunk_size;
	int	chunk_max;
	int	ra_count;

	chunk_size = my_sqrt(a->size);
	chunk_max = chunk_size - 1;
	while (a->size > 0)
	{
		ra_count = 0;
		while (ra_count < a->size)
		{
			if (a->top->value <= chunk_max)
			{
				pb(a, b, opt);
				ra_count = 0;
			}
			else
			{
				ra(a, 1, opt);
				ra_count++;
			}
		}
		chunk_max += chunk_size;
	}
}
void	rotate_b_to_top(t_stack *stack, int index, t_options *opt)
{
	int	i;

	i = 0;
	if ((stack->size / 2) >= index)
	{
		while (i < index)
		{
			rb(stack, 1, opt);
			i++;
		}
	}
	else
	{
		while (i < stack->size - index)
		{
			rrb(stack, 1, opt);
			i++;
		}
	}
}

void	push_back(t_stack *a, t_stack *b, t_options *opt)
{
	int	max_index;

	while (b->size > 0)
	{
		max_index = find_max_index(b);
		rotate_b_to_top(b, max_index, opt);
		pa(a, b, opt);
	}
}

void	medium_sort(t_stack *a, t_stack *b, t_options *opt)
{
	opt->calculation = MEDIUM;
	if (a->size <= 5)
		return (switch_sort_by_stack_size(a, b, opt));
	compress(a);
	push_chunks(a, b, opt);
	push_back(a, b, opt);
}
