
#include "push_swap.h"

long	ft_atol(char *arg)
{
	size_t	i;
	int		sign;
	long	tmp;

	i = 0;
	sign = 1;
	tmp = 0;
	while ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == 32)
		i++;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		tmp = tmp * 10 + (arg[i] - '0');
		i++;
	}
	return (tmp * sign);
}

int	is_nums(char *arg)
{
	long n;
	int i;

	i = 0;
	if (!arg || arg[0] == '\0')
		return (0);
	//先頭の符号だけ許可
	if (arg[0] == '-' || arg[0] == '+')
		i = 1;
	//arg= "-"の時をケア
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (!is_num(arg[i]))
			return (0);
		i++;
	}
	//int範囲チェック
	n = ft_atol(arg);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

//重複チェック
int is_duplicate(t_stack *stack, int n)
{
	int i;

	i = 0;
	if (!stack)
		return (0);
	while (i < stack->size)
	{
		if (stack->data[i] == n)
			return (1);
		i++;
	}
	return (0);
}


