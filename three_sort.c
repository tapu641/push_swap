/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/26 00:00:00 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack *a, t_options *opt)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top < mid && mid < bot)
		return ;
	else if (top < mid && mid > bot && top < bot)
	{
		rra(a, 1, opt);
		sa(a, 1, opt);
	}
	else if (top > mid && mid < bot && top < bot)
		sa(a, 1, opt);
	else if (top < mid && mid > bot && top > bot)
		rra(a, 1, opt);
	else if (top > mid && mid < bot && top > bot)
		ra(a, 1, opt);
	else
	{
		sa(a, 1, opt);
		rra(a, 1, opt);
	}
}
