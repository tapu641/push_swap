/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:03:12 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/04 18:45:51 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (!str)
		return (NULL);
	if (str_len <= start)
		return (ft_strdup(""));
	if (start + len > str_len)
		len = str_len - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!dest)
		return (NULL);
	while (i < len && str[start + i] != '\0')
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
