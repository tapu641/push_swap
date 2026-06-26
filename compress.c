/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/26 00:00:00 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	t_list	*current;
	int		max_index;
	int		max_val;
	int		index;

	current = stack->top;
	max_val = current->value;
	max_index = 0;
	index = 0;
	while (current)
	{
		if (max_val < current->value)
		{
			max_val = current->value;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	return (max_index);
}

int	my_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	*save_originals(t_stack *a)
{
	int		*orig;
	t_list	*cur;
	int		i;

	orig = malloc(sizeof(int) * a->size);
	if (!orig)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	cur = a->top;
	i = 0;
	while (cur)
	{
		orig[i] = cur->value;
		cur = cur->next;
		i++;
	}
	return (orig);
}

static int	calc_rank(int *orig, int size, int i)
{
	int	rank;
	int	j;

	rank = 0;
	j = 0;
	while (j < size)
	{
		if (orig[j] < orig[i])
			rank++;
		j++;
	}
	return (rank);
}

void	compress(t_stack *a)
{
	int		*orig;
	t_list	*cur;
	int		i;

	orig = save_originals(a);
	cur = a->top;
	i = 0;
	while (cur)
	{
		cur->value = calc_rank(orig, a->size, i);
		cur = cur->next;
		i++;
	}
	free(orig);
}
