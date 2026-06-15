/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:14:10 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/15 21:15:13 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> //INT_MIN,INT_MAX
# include <stdlib.h> //malloc,free,exit
# include <stdio.h>  //malloc,free,exit
# include <unistd.h> //write
//# include "libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_strategy
{
	int	mode;
	int	is_bench;
	int	flag_count;
}		t_strategy;

typedef struct s_opt_stats
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	double	disorder;
}			t_opt_stats;



typedef struct s_stack
{
	t_list		*stack_a_top;
	t_list		*stack_b_top;
	int			size;
	t_strategy	*strategy;
	t_opt_stats	*opt_stats;
}				t_stack;

# define SIMPLE 0
# define MEDIUM 1
# define COMPLEX 2
# define ADAPTIVE 3
# define TRUE 1
# define FALSE 0

//ノード操作
t_list  *node_new(int value);
void    push_front(t_list **head, t_list *node);
t_list  *pop_front(t_list **head);

// スタック操作
t_stack *stack_new(void);
void    stack_free(t_stack *stack);

// 操作関数
void    sa(t_stack *stack,int flag);
void    sb(t_stack *stack,int flag);
void    ss(t_stack *stack);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *stack,int flag);
void    rb(t_stack *stack,int flag);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *stack,int flag);
void    rrb(t_stack *stack,int flag);
void    rrr(t_stack *a, t_stack *b);


// ソートアルゴリズム
void	simple_sort(t_stack *a, t_stack *b);
void	complex_sort(t_stack *stack_a);

#endif
