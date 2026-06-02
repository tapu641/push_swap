/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 19:06:44 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/30 15:49:18 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
