/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:08:05 by rnagai            #+#    #+#             */
/*   Updated: 2026/05/29 22:25:13 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int main(int argc, char **argv)
{
	int i;
	int failure_flag;
	int tmp;
	t_list **stack_a;
	t_list *new_node;

	
	i = 0;
	// 引数1以下なら終了
	if (argc <= 2)
		return (SUCCESS_MAIN);
	// スタックの作成
	while (*argv[i] != '\0')
	{
		// atoiに失敗したらErrorを出力して終了。
		tmp = ft_atoi(argv[i], &failure_flag);
		if (failure_flag == -1)
		{
			write(2, "Error\n", 6);
			return (FAILURE_MAIN);
		}
		new_node = ft_lstnew(argv[i]);
		if (new_node == NULL)
			write(2, "Error\n", 6); //これいるか？？
			return (FAILURE_MAIN);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	
	
	return (SUCCESS_MAIN);
}


//#include <stdlib.h>

//int main(void)
//{
//	printf("d: %d", atoi("hofa"));
//}