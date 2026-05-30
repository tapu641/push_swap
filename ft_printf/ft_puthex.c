/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sito <sito@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:42:13 by sito              #+#    #+#             */
/*   Updated: 2026/05/23 11:50:24 by sito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int flag)
{
	int		count;
	char	*s;

	if (flag == 0)
		s = "0123456789abcdef";
	else
		s = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, flag);
	if (write(1, &s[n % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}
