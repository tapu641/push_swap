/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:08:05 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/06 14:04:57 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	handle_flags(char *arg, t_strategy *strategy)
{
	int not_sort_flag;
	int not_bench_flag;

	not_sort_flag = 0;
	not_bench_flag = 0;
	
	if (ft_strcmp(&arg[0], "simple"))
		strategy->strategy_flag = 0;
	else if (ft_strcmp(&arg[0], "medium"))
		strategy->strategy_flag = 1;
	else if (ft_strcmp(&arg[0], "complex"))
		strategy->strategy_flag = 3;
	else if (ft_strcmp(&arg[0], "adaptive"))
		strategy->strategy_flag = 4;
	else
		not_sort_flag = 1;
	if (ft_strcmp(&arg[0], "bench"))
		strategy->is_bench = 1;
	else
		not_bench_flag = 1;
	if (not_sort_flag == 1 && not_bench_flag == 1)
		exit(EXIT_FAILURE);
}

int	parse_flags(char **argv, t_strategy *strategy)
{
	int i;
	int flag_count;

	i = 1;
	flag_count = 0;
	while (argv[i][0] == '-' && argv[i][1] == '-')
	{
		// オプション指定があったら構造体に保持
		handle_flags(&argv[i][2], strategy);
		i++;
		flag_count++;
	}
	return (flag_count);
}

int main(int argc, char **argv)
{
	int i;
	int num;
	t_list **stack_a;
	t_list *new_node;
	t_strategy *strategy;
	double	disorder;
	int flag_count;

	i = 1;
	flag_count = 0;
	strategy->strategy_flag = 3;
	strategy->is_bench = 0;

	// フラグの処理
	flag_count = parse_flags(argv, strategy);

	// フラグを除き引数1以下なら終了
	if (argc - flag_count <= 2)
		return (SUCCESS_MAIN);
	// mallocしてint型の配列に格納する
	int	*num_arr = (int *)malloc(sizeof(int) * (argc - flag_count - 1));
	while (*argv[i] != '\0')
	{
		// atoiに失敗したらErrorを出力して終了。
		num_arr[i - flag_count - 1] = ft_atoi(argv[i]);
		i++;
	}
	int num_arr_len = i - flag_count - 1;
	// disorderチェック
	double disorder = calc_disorder(num_arr, num_arr_len);
	
	// スタックの作成
	i = 0;
	while (i < num_arr_len)
	{
		new_node = ft_lstnew(num_arr[i]);
		if (new_node == NULL)
			write(2, "Error\n", 6); //これいるか？？
			return (FAILURE_MAIN);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	
	// disorderかフラグごとに処理を分岐
	if (disorder < 0.25 || strategy->strategy_flag == 0)
		simple_sort();
	else if (disorder < 0.50 || strategy->strategy_flag == 1)
		medium_sort();
	else
		complex_sort();
	return (SUCCESS_MAIN);
}


//#include <stdlib.h>

//int main(void)
//{
//	printf("d: %d", atoi("hofa"));
//}