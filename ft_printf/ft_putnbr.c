/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sito <sito@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:50:49 by sito              #+#    #+#             */
/*   Updated: 2026/05/23 11:59:30 by sito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count;
	char	*s;

	s = "0123456789";
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		n = -n;
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	if (write(1, &s[n % 10], 1) == -1)
		return (-1);
	count++;
	return (count);
}
