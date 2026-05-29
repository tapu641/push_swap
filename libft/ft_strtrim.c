/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 21:07:03 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/13 22:02:16 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *set)
{
	size_t	i;
	size_t	set_len;

	i = 0;
	set_len = ft_strlen(set);
	while (i < set_len)
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	init;
	size_t	last;
	char	*dest;
	char	*result;

	init = 0;
	last = ft_strlen(s1);
	while (is_charset(s1[init], set))
		init++;
	while (init < last && is_charset(s1[last - 1], set))
		last--;
	dest = (char *)malloc((sizeof(char) * (last - init + 1)));
	if (!dest)
		return (NULL);
	result = dest;
	while (init < last)
	{
		*dest = s1[init];
		dest++;
		init++;
	}
	*dest = '\0';
	return (result);
}
