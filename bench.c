/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/07/12 16:02:55 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

double	calc_disorder(int *num_arr, int arr_len)
{
	int	total_pair;
	int	mistakes;
	int	i;
	int	j;

	total_pair = 0;
	mistakes = 0;
	i = 0;
	while (i < arr_len - 1)
	{
		j = 0;
		while (i + j < arr_len - 1)
		{
			if (num_arr[i] > num_arr[i + j + 1])
				mistakes++;
			total_pair++;
			j++;
		}
		i++;
	}
	if (mistakes == 0)
		return (0.0);
	return ((double)mistakes / total_pair);
}

char	*get_mode(int mode)
{
	if (mode == SIMPLE)
		return ("Simple");
	if (mode == MEDIUM)
		return ("Medium");
	if (mode == COMPLEX)
		return ("Complex");
	if (mode == ADAPTIVE)
		return ("Adaptive");
	return ("Not selected");
}

char	*get_calc(int calculation)
{
	if (calculation == SIMPLE)
		return ("O(n²)");
	if (calculation == MEDIUM)
		return ("O(n√n)");
	if (calculation == COMPLEX)
		return ("O(n log n)");
	return ("Not selected");
}

int	calc_total_ops(t_options *opt)
{
	int	total;

	total = opt->sa + opt->sb + opt->ss;
	total += opt->pa + opt->pb;
	total += opt->ra + opt->rb + opt->rr;
	total += opt->rra + opt->rrb + opt->rrr;
	return (total);
}

void	print_bench(t_options *opt)
{
	ft_printf("[bench] disorder: %d%%\n", opt->disorder);
	ft_printf("[bench] strategy: %s / %s\n",
		get_mode(opt->mode), get_calc(opt->calculation));
	ft_printf("[bench] total_ops: %i\n", calc_total_ops(opt));
	ft_printf("[bench] sa: %i  sb: %i  ss: %i  ", opt->sa, opt->sb, opt->ss);
	ft_printf("pa: %i  pb: %i\n", opt->pa, opt->pb);
	ft_printf("[bench] ra: %i  rb: %i  rr: %i  ", opt->ra, opt->rb, opt->rr);
	ft_printf("rra: %i rrb: %i rrr: %i\n", opt->rra, opt->rrb, opt->rrr);
}
