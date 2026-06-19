/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:08:05 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/19 22:54:54 by rnagai           ###   ########.fr       */
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
	if (!stack || !new)
		return ;
	if (!stack->stack_top)
	{
		stack->stack_top = new;
		return ;
	}
	while (stack->stack_top->next != NULL)
	{
		stack->stack_top = stack->stack_top->next;
	}
	stack->stack_top->next = new;
}

int	handle_flags(char *arg, t_options *opt)
{
	int not_sort_flag;
	int not_bench_flag;

	not_sort_flag = 0;
	not_bench_flag = 0;
	
	if (ft_strcmp(&arg[0], "simple"))
		opt->mode = SIMPLE;
	else if (ft_strcmp(&arg[0], "medium"))
		opt->mode = MEDIUM;
	else if (ft_strcmp(&arg[0], "complex"))
		opt->mode = COMPLEX;
	else if (ft_strcmp(&arg[0], "adaptive"))
		opt->mode = ADAPTIVE;
	else
		not_sort_flag = 1;
	if (ft_strcmp(&arg[0], "bench"))
		opt->is_bench = TRUE;
	else
		not_bench_flag = 1;
	if (not_sort_flag == 1 && not_bench_flag == 1)
		return (FALSE);
	return(TRUE);
}

void	parse_flags(char **argv, t_options *opt)
{
	int i;

	i = 1;
	while (argv[i][0] == '-' && argv[i][1] == '-')
	{
		// オプション指定があったら構造体に保持
		if(handle_flags(&argv[i][2], opt))
		{
			i++;
			opt->flag_count++;
		}
		else
		{
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
int apply_index(int *num_arr, int *num_index_arr, int arr_len, int min_val)
{
	int i;
	int j;
	int min_border;

	i = 0;
	min_border = INT_MIN;
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{
			if (num_arr[j] > min_border && num_arr[j] < min_val)
			{
				min_val = num_arr[j];
				num_index_arr[i] = j;
			}
			j++;
		}
		min_border = min_val;
		min_val = INT_MAX;
		i++;
	}
}

int	*assign_index(int *num_arr, int arr_len)
{
	int i;
	int j;
	int min_border;
	int min_val;
	int	*num_index_arr;

	min_val = INT_MAX;
	num_index_arr = (int *)malloc(sizeof(int) * arr_len);
	if (!num_index_arr)
		return (NULL);
	apply_index(num_arr, num_index_arr, arr_len, min_val);
	return (num_index_arr);
}

void	build_stack(int argc, char **argv, t_stack *stack, t_options *opt)
{
	int	*num_arr;
	int *num_index;
	int	arr_len;
	int	i;
	t_list	*new_node;

	// 引数が使用可能なものかどうか確認する。
	num_arr = validate_args(argc, argv, opt, &arr_len);
	num_index = assign_index(num_arr, arr_len);

	// disorderの計算
	opt->disorder = calc_disorder(num_arr, arr_len);
	i = 0;

	// スタックの作成
	while (i < arr_len)
	{
		new_node = ft_lstnew(num_arr[i], num_index[i]);
		if (new_node == NULL)
			print_error();
		ft_lstadd_back_stack(stack, new_node);
	}
	// スタックの全体のvalueと比較し小さい順にindexをる。
}

void	initialize_stack(t_stack *stack)
{
	stack->stack_top = NULL;
	stack->size = 0;
}

void	initialize_options(t_options *opt)
{
	opt = malloc(sizeof(t_options));
	if (!opt)
		print_error();
	opt->sa = 0;
	opt->sb = 0;
	opt->ss = 0;
	opt->pa = 0;
	opt->pb = 0;
	opt->ra = 0;
	opt->rb = 0;
	opt->rr = 0;
	opt->rra = 0;
	opt->rrb = 0;
	opt->rrr = 0;
	opt->disorder = 0;
	opt->mode = ADAPTIVE;
	opt->is_bench = FALSE;
	opt->flag_count = 0;
}

int	*validate_args(int argc, char **argv, t_options *opt, int *arr_len)
{
	int	flag_count;
	int	*num_arr;
	int	i;

	// フラグの処理
	parse_flags(argv, opt);
	flag_count = opt->flag_count;

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
	return (num_arr);
}

void	switch_algorithm(t_stack *stack_a, t_stack *stack_b, t_options *opt)
{
	int	mode;
	int	disorder;
	
	mode = opt->mode;
	disorder = opt->disorder;
	
	if (mode == SIMPLE)
		simple_sort(stack_a, stack_b);
	else if (mode == MEDIUM)
		medium_sort(stack_a, stack_b); 
	else if (mode == COMPLEX)
		complex_sort(stack_a, stack_b);
	else if (disorder < 0.20)
		simple_sort(stack_a, stack_b);
	else if (disorder < 0.50)
		medium_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
}

int main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_options	*opt;

	// フラグを除き引数1以下なら終了
	//if (argc - flag_count <= 2)
	//	return (EXIT_SUCCESS);
	
	// stack_a, stack_bの初期化
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	opt = malloc(sizeof(t_options));
	if (!stack_a || !stack_b || !opt)
		print_error();
	initialize_stack(stack_a);
	initialize_stack(stack_b);
	initialize_options(opt);
	//スタックの作成
	build_stack(argc, argv, stack_a, opt);
	// mallocしてint型の配列に格納する
	
	// disorderかフラグごとに処理を分岐
	switch_algorithm(stack_a, stack_b, opt);

	return (EXIT_SUCCESS);
}
