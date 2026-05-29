/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 19:06:44 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/29 19:26:54 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *fail_flag)
{
	int		minus_flag;
	long	num;

	minus_flag = 0;
	num = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_flag = 1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		if (num > LONG_MAX / 10 && minus_flag == 0)
			return ((int)LONG_MAX);
		if ((num * 10 - 1) / 10 > LONG_MAX / 10 && minus_flag == 1)
			return ((int)LONG_MIN);
		num = num * 10 + (*str - '0');
		str++;
	}
	if (minus_flag == 1)
		num = -num;
	return (num);
}
