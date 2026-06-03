/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:14:10 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/25 20:47:27 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> //INT_MIN,INT_MAX
# include <stdlib.h> //malloc,free,exit
# include <unistd.h>    // write
# include "libft.h"

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
    t_list  *top;
    int     size;
}   t_stack;

# define SUCCESS_MAIN 0
# define FAILURE_MAIN 1

//ノード操作
t_list  *node_new(int value);
void    push_front(t_list **head, t_list *node);
t_list  *pop_front(t_list **head);

// スタック操作
t_stack *stack_new(int max);
void    stack_free(t_stack *stack);

// 操作関数
void    sa(t_stack *stack);
void    sb(t_stack *stack);
void    ss(t_stack *stack);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *stack);
void    rb(t_stack *stack);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *stack);
void    rrb(t_stack *stack);
void    rrr(t_stack *a, t_stack *b);

#endif
