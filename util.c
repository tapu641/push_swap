/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:18:47 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/29 19:25:55 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_num(char c)
{
	return (c >= '0' && c <= '9');
}
int is_nums(char *arg)
{
	int i;
	
	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
	{
		if (!is_nums(arg[i]) && arg[i] != '-' && arg[i] != '+')
			return (0);
		i++;
	}
	return (1);
}
