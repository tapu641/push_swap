/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:41:22 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/09 21:59:53 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_sort(t_stack *stack_a)
{
	t_stack	*stack_b;
	t_stack	*stack_ptr;
	int		max_bits;
	
	stack_ptr = stack_a;
	int i = 1;
	while (stack_ptr->top != NULL)
	{
		if ( > max_bits)
		stack_ptr->top = stack_ptr->top->next;
	}
	
	while (i < ビット数分)

		 スタックaのポインタをtmpに保持
		 while (tmp（スタック）を進めてtmpがNULLになるまで)
		
			 i桁目を見て0ならpb、1ならraする。
			 
		
		 while (スタックbがNULLなるまで)

			 paする。
	
		 i++;
}


//void	complex_sort(t_list **stack_a)
//{
//	t_list	**stack_b;

//	 int i = 1;
//	// while (スタックaのサイズ分)
	
//		// スタックaの最大ビット数分保持
	
//	// while (i < ビット数分)

//		// スタックaのポインタをtmpに保持
//		// while (tmp（スタック）を進めてtmpがNULLになるまで)
		
//			// i桁目を見て0ならpb、1ならraする。
//			// 
		
//		// while (スタックbがNULLなるまで)

//			// paする。
	
//		// i++;
//}