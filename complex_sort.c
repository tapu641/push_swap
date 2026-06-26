/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:41:22 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/26 20:20:22 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits_count(t_stack *stack_a)
{
	t_list	*current;
	int		num;
	int		max_bits;
	int		bit_count;

	current = stack_a->top;
	max_bits = 0;
	while (current != NULL)
	{
		num = current->index;
		bit_count = 0;
		while (num > 0)
		{
			num = num >> 1;
			bit_count++;
		}
		if (bit_count > max_bits)
			max_bits = bit_count;
		current = current->next;
	}
	return (max_bits);
}

static int	check_option(t_stack *stack_a, t_options *opt)
{
	opt->calculation = COMPLEX;
	return (stack_a->size);
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b, t_options *opt)
{
	int	max_bits;
	int	stack_a_size;
	int	i;
	int	j;

	stack_a_size = check_option(stack_a, opt);
	max_bits = get_max_bits_count(stack_a);
	i = 0;
	if (stack_a_size <= 5)
		return (switch_sort_by_stack_size(stack_a, stack_b, opt));
	while (i < max_bits)
	{
		j = 0;
		while (j < stack_a_size)
		{
			if ((stack_a->top->index >> i) & 1)
				ra(stack_a, 1, opt);
			else
				pb(stack_a, stack_b, opt);
			j++;
		}
		while (stack_b->top != NULL)
			pa(stack_a, stack_b, opt);
		i++;
	}
}
