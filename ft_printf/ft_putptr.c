/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sito <sito@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:37:42 by sito              #+#    #+#             */
/*   Updated: 2026/05/23 12:45:04 by sito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_long(unsigned long n)
{
	char	*digits;
	int		count;

	digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_long(n / 16);
	if (write(1, &digits[n % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	if (!ptr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (ft_puthex_long((unsigned long)ptr) + 2);
}
