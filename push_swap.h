/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:14:10 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/26 19:36:50 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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

typedef struct s_stack
{
	t_list		*top;
	int			size;
}				t_stack;


typedef struct s_options
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
	int		mode;
	int		calculation;
	int		is_bench;
	int		flag_count;
}			t_options;


# define SIMPLE 0
# define MEDIUM 1
# define COMPLEX 2
# define ADAPTIVE 3
# define TRUE 1
# define FALSE 0
# define IDX_INIT 0

// ノード操作 (node_operations.c)
t_list	*node_new(int value);
void	push_front(t_list **head, t_list *node);
t_list	*pop_front(t_list **head);

// スタック操作 (stack.c)
t_list	*ft_lstnew(int value, int index);
void	ft_lstadd_back(t_stack *stack, t_list *new);
t_stack	*stack_new(void);
void	stack_free(t_stack *stack);

// swap操作 (swap.c)
void	sa(t_stack *stack, int flag, t_options *opt);
void	sb(t_stack *stack, int flag, t_options *opt);
void	ss(t_stack *a, t_stack *b, t_options *opt);

// push操作 (push.c)
void	pa(t_stack *a, t_stack *b, t_options *opt);
void	pb(t_stack *a, t_stack *b, t_options *opt);

// rotate操作 (rotate_ops.c)
void	ra(t_stack *stack, int flag, t_options *opt);
void	rb(t_stack *stack, int flag, t_options *opt);
void	rr(t_stack *a, t_stack *b, t_options *opt);

// reverse rotate操作 (rev_rotate_ops.c)
void	rra(t_stack *stack, int flag, t_options *opt);
void	rrb(t_stack *stack, int flag, t_options *opt);
void	rrr(t_stack *a, t_stack *b, t_options *opt);

// ユーティリティ (util.c)
long	ft_atol(char *arg, int i);
int		ft_strcmp(const char *s1, const char *s2);
void	print_error(void);

// パース (parse.c)
int		handle_flags(char *arg, t_options *opt);
void	parse_flags(char **argv, t_options *opt);
int		apply_index(int *num_arr, int *num_index_arr, int arr_len, int min_val);
int		*assign_index(int *num_arr, int arr_len);
int		*validate_args(int argc, char **argv, t_options *opt, int *arr_len);

// ベンチマーク (bench.c)
double	calc_disorder(int *num_arr, int arr_len);
char	*get_mode(int mode);
char	*get_calc(int calculation);
int		calc_total_ops(t_options *opt);
void	print_bench(t_options *opt);

// 初期化・メイン (main.c)
void	initialize_stack(t_stack *stack);
void	initialize_options(t_options *opt);
void	build_stack(int argc, char **argv, t_stack *stack, t_options *opt);
void	switch_algorithm(t_stack *stack_a, t_stack *stack_b, t_options *opt);

// ソートアルゴリズム


// simple_sort
void	simple_sort(t_stack *a, t_stack *b, t_options *opt);
void rotate_to_top(t_stack *stack, int min_index);
int find_min_index(t_stack *stack);

// medium_sort
void medium_sort(t_stack *a, t_stack *b);
int find_max_index(t_stack *stack);
int my_sqrt(int n);
void compress(t_stack *a);
void push_chunks(t_stack *a, t_stack *b);
void push_back(t_stack *a, t_stack *b);

// complex sort
void	complex_sort(t_stack *stack_a, t_stack *stack_b, t_options *opt);


// three or five
void three_sort(t_stack *a);
void five_sort(t_stack *a, t_stack *b);
#endif
