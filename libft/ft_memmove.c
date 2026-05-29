/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:46:02 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/04 21:26:39 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t length)
{
	int				i;
	unsigned char	*dest;
	unsigned char	*src;

	i = (int)(length - 1);
	dest = (unsigned char *)d;
	src = (unsigned char *)s;
	if (!src && !dest)
		return (NULL);
	if (dest < src)
		return ((void *)ft_memcpy(d, s, length));
	else
	{
		while (0 <= i)
		{
			dest[i] = src[i];
			i--;
		}
		return ((void *)dest);
	}
}
