/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sito <sito@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:30:57 by sito              #+#    #+#             */
/*   Updated: 2026/05/23 12:53:30 by sito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putptr(void *ptr);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_puthex(unsigned int n, int flag);
int	ft_printf(const char *format, ...);
int	ft_putunsigned(unsigned int n);

#endif
