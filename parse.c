/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/07/19 13:24:47 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_flags(char *arg, t_options *opt)
{
	int	not_sort_flag;
	int	not_bench_flag;

	not_sort_flag = 0;
	not_bench_flag = 0;
	if (ft_strcmp(&arg[0], "simple") == 0)
		opt->mode = SIMPLE;
	else if (ft_strcmp(&arg[0], "medium") == 0)
		opt->mode = MEDIUM;
	else if (ft_strcmp(&arg[0], "complex") == 0)
		opt->mode = COMPLEX;
	else if (ft_strcmp(&arg[0], "adaptive") == 0)
		opt->mode = ADAPTIVE;
	else
		not_sort_flag = 1;
	if (ft_strcmp(&arg[0], "bench") == 0)
		opt->is_bench = TRUE;
	else
		not_bench_flag = 1;
	if (not_sort_flag == 1 && not_bench_flag == 1)
		return (FALSE);
	return (TRUE);
}

void	parse_flags(char **argv, t_options *opt)
{
	int	i;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (handle_flags(&argv[i][2], opt))
		{
			i++;
			opt->flag_count++;
		}
		else
		{
			opt->fail_flag = 1;
			return ;
		}
	}
}

int	apply_index(int *num_arr, int *num_idx_arr, int arr_len, long min_val)
{
	int		i;
	int		j;
	long	min_border;

	i = 0;
	min_border = (long)INT_MIN - 1;
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{
			if (num_arr[j] > min_border && num_arr[j] < min_val)
			{
				min_val = num_arr[j];
				num_idx_arr[j] = i;
			}
			j++;
		}
		min_border = min_val;
		min_val = (long)INT_MAX + 1;
		i++;
	}
	return (0);
}

int	*assign_index(int *num_arr, int arr_len)
{
	long	min_val;
	int		*num_idx_arr;

	min_val = (long)INT_MAX + 1;
	num_idx_arr = (int *)malloc(sizeof(int) * arr_len);
	if (!num_idx_arr)
		return (NULL);
	apply_index(num_arr, num_idx_arr, arr_len, min_val);
	return (num_idx_arr);
}

void	validate_args(int argc, char **argv, t_options *opt, int *arr_len)
{
	int		i;
	long	tmp;

	parse_flags(argv, opt);
	if (opt->fail_flag == 1)
		return ;
	*arr_len = argc - opt->flag_count - 1;
	opt->num_arr = (int *)malloc(sizeof(int) * (*arr_len));
	if (!opt->num_arr)
	{
		opt->fail_flag = 1;
		return ;
	}
	i = 1 + opt->flag_count;
	while (argv[i] != NULL)
	{
		tmp = ft_atol(argv[i], 0);
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			opt->fail_flag = 1;
			return ;
		}
		opt->num_arr[i - 1 - opt->flag_count] = tmp;
		i++;
	}
}
