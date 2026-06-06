/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnagai <rnagai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:14:10 by rnagai            #+#    #+#             */
/*   Updated: 2026/06/02 22:46:38 by rnagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct s_strategy
{
	int strategy_flag;
	int is_bench;
}		t_strategy;


# define SUCCESS_MAIN 0
# define FAILURE_MAIN 1

int	ft_strcmp(const char *s1, const char *s2);
double	calc_disorder(int *num_arr, int len);



#endif