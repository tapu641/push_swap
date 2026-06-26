/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:21:42 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/10 19:19:41 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_to_hex(uintptr_t num, int *fail_flag)
{
	char	*str_hex;
	int		print_count;

	str_hex = "0123456789abcdef";
	print_count = 0;
	if (num >= 16)
	{
		*fail_flag = ptr_to_hex(num / 16, fail_flag);
		if (*fail_flag == -1)
			return (-1);
		print_count += *fail_flag;
	}
	if (ft_putchr(str_hex[num % 16]) == -1)
		return (-1);
	return (print_count + 1);
}

int	ft_putptr(void *p, int *fail_flag)
{
	uintptr_t	ptr;
	int			print_count;
	int			tmp;

	print_count = 0;
	if (p == NULL)
	{
		print_count = ft_putstr("(nil)");
		return (print_count);
	}
	ptr = (uintptr_t)p;
	tmp = ft_putstr("0x");
	if (tmp == -1)
		return (-1);
	print_count += tmp;
	tmp = ptr_to_hex(ptr, fail_flag);
	if (tmp == -1)
		return (-1);
	print_count += tmp;
	return (print_count);
}
