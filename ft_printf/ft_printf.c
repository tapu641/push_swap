/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:02:31 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/20 18:16:59 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_spc(va_list ap, const char *format, size_t i, int *fail_flag)
{
	if (format[i + 1] == 'c')
		return (ft_putchr(va_arg(ap, int)));
	else if (format[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format[i + 1] == 'p')
		return (ft_putptr(va_arg(ap, void *), fail_flag));
	else if (format[i + 1] == 'd')
		return (ft_putdec(va_arg(ap, double), fail_flag));
	else if (format[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int), fail_flag));
	else if (format[i + 1] == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int), fail_flag));
	else if (format[i + 1] == 'x')
		return (ft_puthex_low(va_arg(ap, unsigned int), fail_flag));
	else if (format[i + 1] == 'X')
		return (ft_puthex_up(va_arg(ap, unsigned int), fail_flag));
	else if (format[i + 1] == '%')
		return (ft_putchr('%'));
	return (0);
}

static int	is_specifier(char c)
{
	char	*specifier;
	int		i;

	specifier = "cspdiuxX%";
	i = 0;
	while (specifier[i] != '\0')
	{
		if (specifier[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	handle_format(va_list ap, const char *format, int *fail_flag)
{
	size_t	i;
	int		print_count;

	i = 0;
	print_count = 0;
	while (format[i] != '\0')
	{
		*fail_flag = 0;
		if (format[i] == '%' && is_specifier(format[i + 1]))
		{
			*fail_flag = handle_spc(ap, format, i, fail_flag);
			i += 2;
		}
		else
		{
			*fail_flag = ft_putchr(format[i]);
			i++;
		}
		if (*fail_flag == -1)
			return (*fail_flag);
		print_count += *fail_flag;
	}
	return (print_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_count;
	int		fail_flag;

	fail_flag = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	print_count = handle_format(ap, format, &fail_flag);
	va_end(ap);
	return (print_count);
}

//#include "ft_printf.h"
//#include <stdio.h>
//
//int main()
//{
//	int num = 1234;
//	printf("%d\n",ft_printf("c: %c\n", 'a'));
//	printf("%d\n",printf("c: %c\n", 'a'));
//	printf("\n");
//	printf("%d\n",ft_printf("s: %s\n", "hello"));
//	printf("%d\n",printf("s: %s\n", "hello"));
//	printf("\n");
//	printf("%d\n",ft_printf("p: %p\n", &num));
//	printf("%d\n",printf("p: %p\n", &num));
//	printf("\n");
//	printf("%d\n",ft_printf("d: %d\n", num));
//	printf("%d\n",printf("d: %d\n", num));
//	printf("\n");
//	printf("%d\n",ft_printf("i: %i\n", -num));
//	printf("%d\n",printf("i: %i\n", -num));
//	printf("\n");
//	printf("%d\n",ft_printf("u: %u\n", num));
//	printf("%d\n",printf("u: %u\n", num));
//	printf("\n");
//	printf("%d\n",ft_printf("x: %x\n", num));
//	printf("%d\n",printf("x: %x\n", num));
//	printf("\n");
//	printf("%d\n",ft_printf("X: %X\n", num));
//	printf("%d\n",printf("X: %X\n", num));
//	printf("\n");
//	printf("%d\n",ft_printf("%%\n"));
//	printf("%d\n",printf("%%\n"));
//}
//
//#include <unistd.h>
//int	main(void)
//{
//	int	ret;
//
//	close(STDOUT_FILENO);
//	ret = ft_printf("hello\n");
//
//	if (ret == -1)
//		write(2, "OK: ft_printf returned -1\n", 26);
//	else
//		write(2, "NG", 2);
//	return (0);
//}