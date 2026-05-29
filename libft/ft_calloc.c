/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:09:59 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/04 21:27:34 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*res;

	if (nmemb == 0 || size == 0)
	{
		res = (void *)malloc(0);
		return (res);
	}
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	bytes = nmemb * size;
	res = (void *)malloc(bytes);
	if (!res)
		return (NULL);
	res = ft_memset(res, 0, bytes);
	return (res);
}
