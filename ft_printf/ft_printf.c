/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sito <sito@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:30:25 by sito              #+#    #+#             */
/*   Updated: 2026/05/23 13:00:26 by sito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	judge_next_word(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar((char)va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		count += ft_putunsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		count += ft_puthex(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		count += ft_puthex(va_arg(arg, unsigned int), 1);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

static int	process_format(va_list arg, const char *format, int *count)
{
	int	tmp;
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			tmp = judge_next_word(arg, format[i]);
			if (tmp == -1)
				return (-1);
			*count += tmp;
		}
		else if (format[i] != '%')
		{
			tmp = write(1, &format[i], 1);
			if (tmp == -1)
				return (-1);
			*count += tmp;
		}
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(arg, format);
	if (process_format(arg, format, &count) == -1)
		return (-1);
	va_end(arg);
	return (count);
}
