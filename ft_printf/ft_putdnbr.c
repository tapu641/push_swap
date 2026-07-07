/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:49:22 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/20 18:15:09 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec(double num, int *fail_flag)
{
	int	integer;
	int	dec;

	integer = num * 100;
	dec = (num * 10000) - (integer * 100);
	if (num == 1)
		return (ft_putstr("100.00"));
	if (ft_putnbr(integer, fail_flag) == -1)
		return (-1);
	if (ft_putchr('.') == -1)
		return (-1);
	if (dec < 10)
	{
		if (ft_putchr('0') == -1)
			return (-1);
	}
	if (ft_putnbr(dec, fail_flag) == -1)
		return (-1);
	return (PRINT_COUNT);
}
