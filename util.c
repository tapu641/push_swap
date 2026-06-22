
#include "push_swap.h"

long	ft_atol(char *arg, int i)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
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
		num = num * 10 + (arg[i] - '0');
		if (num > INT_MAX || num < INT_MIN)
			print_error();  // これで問題ないんだっけ、、メモリリーク起きないか忘れた。
		i++;
		if (arg[i] == '\0')
			return (num * sign);
	}
	print_error();
	return ((long)INT_MIN - 1);
}


int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void print_error()
{
	// free_stack() これはいらないよな。
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}


