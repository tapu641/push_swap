#include "push_swap.h"
#include "ft_printf.h"

void	initialize_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void	initialize_options(t_options *opt)
{
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
	opt->calculation = SIMPLE;
	opt->is_bench = FALSE;
	opt->flag_count = 0;
}

void	build_stack(int argc, char **argv, t_stack *stack, t_options *opt)
{
	int		*num_arr;
	int		*num_index;
	int		arr_len;
	int		i;
	t_list	*new_node;

	num_arr = validate_args(argc, argv, opt, &arr_len);
	num_index = assign_index(num_arr, arr_len);
	opt->disorder = calc_disorder(num_arr, arr_len);
	i = 0;
	while (i < arr_len)
	{
		new_node = ft_lstnew(num_arr[i], num_index[i]);
		if (new_node == NULL)
			print_error();
		ft_lstadd_back(stack, new_node);
		i++;
	}
}

void	switch_algorithm(t_stack *stack_a, t_stack *stack_b, t_options *opt)
{
	int		mode;
	double	disorder;

	mode = opt->mode;
	disorder = opt->disorder;
	if (mode == SIMPLE)
		simple_sort(stack_a, stack_b, opt);
	//else if (mode == MEDIUM)
	//	medium_sort(stack_a, stack_b);
	else if (mode == COMPLEX)
		complex_sort(stack_a, stack_b, opt);
	else if (disorder < 0.20)
		simple_sort(stack_a, stack_b, opt);
	//else if (disorder < 0.50)
	//	medium_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b, opt);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_options	*opt;

	if (argc < 2)
		return (EXIT_SUCCESS);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	opt = malloc(sizeof(t_options));
	if (!stack_a || !stack_b || !opt)
		print_error();
	initialize_stack(stack_a);
	initialize_stack(stack_b);
	initialize_options(opt);
	build_stack(argc, argv, stack_a, opt);
	switch_algorithm(stack_a, stack_b, opt);
	if (opt->is_bench)
		print_bench(opt);
	return (EXIT_SUCCESS);
}
