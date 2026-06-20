/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 21:28:37 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/24 18:22:16 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(int str)
{
	char	c;

	c = (char)str;
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	flag;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		flag = write(1, &str[i], 1);
		if (flag == -1)
			return (flag);
		i++;
	}
	return (i);
}
