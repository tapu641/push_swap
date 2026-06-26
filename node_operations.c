/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:00:00 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/26 00:00:00 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*node_new(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_front(t_list **head, t_list *node)
{
	if (!head || !node)
		return ;
	node->next = *head;
	*head = node;
}

t_list	*pop_front(t_list **head)
{
	t_list	*tmp;

	if (!head || !(*head))
		return (NULL);
	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	return (tmp);
}
