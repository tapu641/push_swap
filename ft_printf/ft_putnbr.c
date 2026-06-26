/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:33:48 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/28 21:16:06 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num, int *fail_flag)
{
	int	print_count;

	print_count = 0;
	if (num == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		if (ft_putchr('-') == -1)
			return (-1);
		print_count++;
		num = -num;
	}
	if (num >= 10)
	{
		*fail_flag = ft_putnbr(num / 10, fail_flag);
		if (*fail_flag == -1)
			return (-1);
		print_count += *fail_flag;
	}
	if (ft_putchr(num % 10 + '0') == -1)
		return (-1);
	return (print_count + 1);
}

int	ft_putunbr(unsigned int num, int *fail_flag)
{
	long	n;
	int		print_count;

	n = num;
	print_count = 0;
	if (num >= 10)
	{
		*fail_flag = ft_putunbr(num / 10, fail_flag);
		if (*fail_flag == -1)
			return (-1);
		print_count += *fail_flag;
	}
	if (ft_putchr(n % 10 + '0') == -1)
		return (-1);
	return (print_count + 1);
}

int	ft_puthex_low(unsigned int n, int *fail_flag)
{
	char	*str_hex;
	int		print_count;

	str_hex = "0123456789abcdef";
	print_count = 0;
	if (n >= 16)
	{
		*fail_flag = ft_puthex_low(n / 16, fail_flag);
		if (*fail_flag == -1)
			return (-1);
		print_count += *fail_flag;
	}
	if (ft_putchr(str_hex[n % 16]) == -1)
		return (-1);
	return (print_count + 1);
}

int	ft_puthex_up(unsigned int n, int *fail_flag)
{
	char	*str_hex;
	int		print_count;

	str_hex = "0123456789ABCDEF";
	print_count = 0;
	if (n >= 16)
	{
		*fail_flag = ft_puthex_up(n / 16, fail_flag);
		if (*fail_flag == -1)
			return (-1);
		print_count += *fail_flag;
	}
	if (ft_putchr(str_hex[n % 16]) == -1)
		return (-1);
	return (print_count + 1);
}
