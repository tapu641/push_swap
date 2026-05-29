/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:27:46 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/04 21:27:13 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*dest;

	dest = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			dest = (char *)str;
		}
		str++;
	}
	if (*str == '\0' && (char)c == '\0')
	{
		dest = (char *)str;
	}
	return (dest);
}
