/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 21:44:41 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/15 21:12:42 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_word(const char *str, char charset)
{
	int	count;
	int	i;
	int	init_flag;

	count = 0;
	i = 0;
	init_flag = 1;
	while (str[i] != '\0')
	{
		if (str[i] == charset)
			init_flag = 1;
		if (init_flag == 1 && str[i] != charset)
		{
			count++;
			init_flag = 0;
		}
		i++;
	}
	return (count);
}

static int	count_letter(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != charset)
	{
		i++;
	}
	return (i);
}

static char	*ft_strndup(const char *str, size_t length)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (length + 1));
	if (!dest)
		return (NULL);
	while (i < length)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static	char	**free_all(char **res, size_t i)
{
	while (i)
	{
		free(res[i]);
		i--;
	}
	free(res[i]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *str, char charset)
{
	size_t	i;
	char	**res;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (!res)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == charset)
			str++;
		else
		{
			res[i] = ft_strndup(str, count_letter(str, charset));
			if (!res[i])
				return (free_all(res, i));
			i++;
			while (*str != charset && *str != '\0')
				str++;
		}
	}
	res[i] = NULL;
	return (res);
}
