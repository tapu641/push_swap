/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/26 00:00:00 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *stack)
{
	t_list	*current;
	int		min_index;
	int		min_val;
	int		index;

	current = stack->top;
	min_val = current->value;
	min_index = 0;
	index = 0;
	while (current)
	{
		if (min_val > current->value)
		{
			min_val = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	rotate_to_top(t_stack *stack, int min_index, t_options *opt)
{
	int	i;

	i = 0;
	if ((stack->size / 2) >= min_index)
	{
		while (i < min_index)
		{
			ra(stack, 1, opt);
			i++;
		}
	}
	else
	{
		while (i < stack->size - min_index)
		{
			rra(stack, 1, opt);
			i++;
		}
	}
}

void	simple_sort(t_stack *a, t_stack *b, t_options *opt)
{
	int	min_index;

	opt->calculation = SIMPLE;
	if (a->size <= 5)
		return (switch_sort_by_stack_size(a, b, opt));
	while (a->size > 0)
	{
		min_index = find_min_index(a);
		rotate_to_top(a, min_index, opt);
		pb(a, b, opt);
	}
	while (b->top)
		pa(a, b, opt);
}
