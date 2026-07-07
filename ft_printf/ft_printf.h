/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:41:46 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/20 18:14:57 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>

# define PRINT_COUNT 5

int	ft_printf(const char *format, ...);
int	ft_putchr(int str);
int	ft_putstr(char *str);
int	ft_putnbr(int num, int *fail_flag);
int	ft_putptr(void *p, int *fail_flag);
int	ft_putdec(double num, int *fail_flag);
int	ft_putunbr(unsigned int num, int *fail_flag);
int	ft_puthex_low(unsigned int n, int *fail_flag);
int	ft_puthex_up(unsigned int n, int *fail_flag);

#endif