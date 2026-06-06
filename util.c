/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:18:47 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/06 14:20:44 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_num(char c)
{
	return (c >= '0' && c <= '9');
}
int is_nums(char *arg)
{
	int i;
	
	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
	{
		if (!is_nums(arg[i]) && arg[i] != '-' && arg[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double	calc_disorder(int *num_arr, int len)
{
	int	mistake;
	int	total;
	int end;
	int i;
	int j;
	
	mistake = 0;
	total = 0;
	i = 0;
	end = len - 1;
	while (i < end)
	{
		j = 0;
		while (i + j < end)
		{
			if (num_arr[i + j] > num_arr[i + j + 1])
				mistake++;
			total++;
			j++;
		}
		i++;
	}
	return ((double)mistake / total);
}

// TODO:しゅうが更新したis_nums関数がatoiの前に呼ばれるようにすれば正常に動作する。
int	ft_atoi(const char *str)
{
	int		sign;
	long	num;
	int		i;

	sign = 1;
	num = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			num = num * 10 + (str[i] - '0');
		else
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (num * sign);
}


