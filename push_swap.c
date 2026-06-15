/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:08:05 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/15 21:16:19 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->value = content;
	res->index = 0;
	res->next = NULL;
	return (res);
}

void	ft_lstadd_back(t_stack *stack, t_list *new)
{
	if (!stack || !new)
		return ;
	if (!stack->stack_a_top)
	{
		stack->stack_a_top = new;
		return ;
	}
	while (stack->stack_a_top->next != NULL)
	{
		stack->stack_a_top = stack->stack_a_top->next;
	}
	stack->stack_a_top->next = new;
}

int	handle_flags(char *arg, t_stack *stack)
{
	int not_sort_flag;
	int not_bench_flag;

	not_sort_flag = 0;
	not_bench_flag = 0;
	
	if (ft_strcmp(&arg[0], "simple"))
		stack->strategy->mode = SIMPLE;
	else if (ft_strcmp(&arg[0], "medium"))
		stack->strategy->mode = MEDIUM;
	else if (ft_strcmp(&arg[0], "complex"))
		stack->strategy->mode = COMPLEX;
	else if (ft_strcmp(&arg[0], "adaptive"))
		stack->strategy->mode = ADAPTIVE;
	else
		not_sort_flag = 1;
	if (ft_strcmp(&arg[0], "bench"))
		stack->strategy->is_bench = TRUE;
	else
		not_bench_flag = 1;
	if (not_sort_flag == 1 && not_bench_flag == 1)
		return (FALSE);
	return(TRUE);
}

void	parse_flags(char **argv, t_stack *stack)
{
	int i;

	i = 1;
	while (argv[i][0] == '-' && argv[i][1] == '-')
	{
		// オプション指定があったら構造体に保持
		if(handle_flags(&argv[i][2], stack))
		{
			i++;
			stack->strategy->flag_count++;
		}
		else
		{
			stack_free(stack);
			write(2, "Error\n", 6); //これいるか？？
			exit(EXIT_FAILURE);
		}
	}
	argv += i;
}

double	calc_disorder(int *num_arr, int arr_len)
{
	int	total_pair;
	int	mistakes;
	int i;
	int j;

	total_pair = 0;
	mistakes = 0;
	i = 0;
	while (i < arr_len - 1)
	{
		j = 0;
		while (i + j < arr_len - 1)
		{
			if (num_arr[i] == num_arr[i + j + 1])
				print_error();
			if (num_arr[i] > num_arr[i + j + 1])
				mistakes++;
			total_pair++;
		}
		i++;
	}
	return (mistakes / total_pair);
}

void	assigh_index(t_stack *stack)
{
	int	idx;
	int	stack_idx;
	int	min_val;

	idx = 0;
	stack_idx = 0;
	min_val = 0;
	while (stack->stack_a_top[stack_idx]->)
}

void	build_stack(int argc, char **argv, t_stack *stack)
{
	int	*num_arr;
	int	arr_len;
	int	i;
	t_list	*new_node;

	// 引数が使用可能なものかどうか確認する。
	num_arr = validate_args(argc, argv, stack, &arr_len);

	// disorderの計算
	stack->opt_stats->disorder = calc_disorder(num_arr, arr_len);
		// スタックの作成
	i = 0;
	while (i < arr_len)
	{
		new_node = ft_lstnew(num_arr[i]);
		if (new_node == NULL)
			print_error();
		ft_lstadd_back_stack(stack, new_node);
	}
	// スタックの全体のvalueと比較し小さい順にindexをる。
	assign_index(stack);
}

void	initialize_stack(t_stack *stack)
{
	stack->stack_a_top = NULL;
	stack->stack_b_top = NULL;
	stack->size = 0;
	stack->strategy = malloc(sizeof(t_strategy));
	if (!stack->strategy)
		print_error();
	stack->strategy->mode = ADAPTIVE;
	stack->strategy->is_bench = FALSE;
	stack->strategy->flag_count = 0;
	stack->opt_stats = malloc(sizeof(t_opt_stats));
	if (!stack->opt_stats)
		print_error();
	stack->opt_stats->sa = 0;
	stack->opt_stats->sb = 0;
	stack->opt_stats->ss = 0;
	stack->opt_stats->pa = 0;
	stack->opt_stats->pb = 0;
	stack->opt_stats->ra = 0;
	stack->opt_stats->rb = 0;
	stack->opt_stats->rr = 0;
	stack->opt_stats->rra = 0;
	stack->opt_stats->rrb = 0;
	stack->opt_stats->rrr = 0;
	stack->opt_stats->disorder = 0;
}

int	*validate_args(int argc, char **argv, t_stack *stack, int *arr_len)
{
	int	flag_count;
	int	*num_arr;
	int	i;

	// フラグの処理
	parse_flags(argv, stack);
	flag_count = stack->strategy->flag_count;

	// arrの長さを測る
	*arr_len = argc - flag_count - 1;
	num_arr = (int *)malloc(sizeof(int) * (*arr_len));
	i = 0;
	while (*argv[i] != '\0')
	{
		// atoiに失敗したらErrorを出力して終了。
		num_arr[i] = ft_atol(argv[i], 0);
		i++;
	}
	return (num_arr)
}

void	switch_algorithm(t_stack *stack)
{
	int	mode;
	int	disorder;
	
	mode = stack->strategy->mode;
	disorder = stack->opt_stats->disorder;
	
	if (mode == SIMPLE)
		simple_sort(stack);
	else if (mode == MEDIUM)
		medium_sort(stack); 
	else if (mode == COMPLEX)
		complex_sort(stack);
	else if (disorder < 0.20)
		simple_sort(stack);
	else if (disorder < 0.50)
		medium_sort(stack);
	else
		complex_sort(stack);
}

int main(int argc, char **argv)
{
	t_stack *stack;

	// フラグを除き引数1以下なら終了
	//if (argc - flag_count <= 2)
	//	return (EXIT_SUCCESS);
	
	// stack_a, stack_bの初期化
	stack = malloc(sizeof(t_stack));
	if (!stack)
		print_error();
	initialize_stack(stack);

	build_stack(argc, argv, stack);
	// mallocしてint型の配列に格納する
	
	// disorderかフラグごとに処理を分岐
	switch_algorithm(stack);

	return (EXIT_SUCCESS);
}
