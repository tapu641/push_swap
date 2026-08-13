/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/07/19 13:43:59 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value, int index)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->value = value;
	res->index = index;
	res->next = NULL;
	return (res);
}

void	ft_lstadd_back(t_stack *stack, t_list *new)
{
	t_list	*current;

	if (!stack || !new)
		return ;
	stack->size++;
	if (!stack->top)
	{
		stack->top = new;
		return ;
	}
	current = stack->top;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
