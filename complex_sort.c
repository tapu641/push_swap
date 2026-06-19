/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:41:22 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/19 22:58:13 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits_count(t_stack *stack)
{
	t_stack	*stack_ptr;
	int	num;
	int max_bits;
	int bit_count;
	
	stack_ptr = stack;
	max_bits = 0;
	while (stack_ptr->top != NULL)
	{
		num = stack_ptr->top->value;
		bit_count = 0;
		while (num > 0)
		{
			num = num >> 1;
			bit_count++;
		}
		if (bit_count > max_bits)
			max_bits = bit_count;
		stack_ptr->top = stack_ptr->top->next;
	}
	return (max_bits);
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b, t_options *opt)
{
	int max_bits;
	int stack_a_size;
	int i;
	int	j;
	
	stack_a_size = stack->stack_a_top->size;
	max_bits = get_max_bits_count(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < stack_a_size)
		{
			if ((stack_a->top->value >> i) & 1)
				ra(stack_a, is_bench);
			else
				pb(stack_a, stack_b);
			j++;
		}	 
		while (stack_b->top != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}
