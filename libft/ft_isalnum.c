/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 20:45:01 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/02 18:46:22 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	flag;

	if (ft_isalpha(c) || ft_isdigit(c))
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}
	return (flag);
}
