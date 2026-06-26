/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/26 00:00:00 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *arg, int i)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == 32)
		i++;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		num = num * 10 + (arg[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num - 1 > INT_MAX))
			print_error();
		i++;
		if (arg[i] == '\0')
			return (num * sign);
	}
	print_error();
	return ((long)INT_MIN - 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	switch_sort_by_stack_size(t_stack *a, t_stack *b, t_options *opt)
{
	if (a->size == 2)
		sa(a, 1, opt);
	else if (a->size == 3)
		three_sort(a, opt);
	else if (a->size <= 5)
		five_sort(a, b, opt);
}

void	free_all(t_stack *stack_a, t_stack *stack_b, t_options *opt)
{
	t_list	*step;

	while (stack_a->top != NULL)
	{
		step = stack_a->top->next;
		free(stack_a->top);
		stack_a->top = step;
	}
	free(stack_a);
	free(stack_b);
	free(opt);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
