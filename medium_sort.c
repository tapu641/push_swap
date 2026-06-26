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

static int	find_chunk_index(t_stack *a, int chunk_max)
{
	t_list	*cur;
	int		index;

	cur = a->top;
	index = 0;
	while (cur)
	{
		if (cur->value <= chunk_max)
			return (index);
		cur = cur->next;
		index++;
	}
	return (-1);
}

void	push_chunks(t_stack *a, t_stack *b, t_options *opt)
{
	int	chunk_size;
	int	chunk_max;
	int	chunk_min;
	int	index;

	chunk_size = my_sqrt(a->size);
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	while (a->size > 0)
	{
		index = find_chunk_index(a, chunk_max);
		if (index == -1)
		{
			chunk_min += chunk_size;
			chunk_max += chunk_size;
		}
		else
		{
			rotate_a_to_top(a, index, opt);
			pb(a, b, opt);
			if (b->top->value < chunk_min + (chunk_size / 2))
				rb(b, 1, opt);
		}
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
