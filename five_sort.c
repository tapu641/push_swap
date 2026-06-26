/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/26 00:00:00 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_sort(t_stack *a, t_stack *b, t_options *opt)
{
	if (a->size == 5)
	{
		rotate_to_top(a, find_min_index(a), opt);
		pb(a, b, opt);
	}
	rotate_to_top(a, find_min_index(a), opt);
	pb(a, b, opt);
	three_sort(a, opt);
	pa(a, b, opt);
	pa(a, b, opt);
}
