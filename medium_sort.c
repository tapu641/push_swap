#include "push_swap.h"

int find_max_index(t_stack *stack)
{
	t_list *current;
	int max_index;
	int max_val;
	int index;

	//ポインタコピーする（stackを動かすとtopが変わるため）
	current = stack->top;
	max_val = current->value;
	max_index = 0;
	index = 0;
	while(current)
	{
		//最大値見つけ次第更新
		if (max_val < current->value)
		{
			max_val = current->value;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	return (max_index);
}

int my_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void push_chunks(t_stack *a, t_stack *b)
{
	int chunk_size;
	int chunk_max;

	chunk_size = my_sqrt(a->size);
	chunk_max = chunk_size;

	while (a->size > 0)
	{
		if (a->top->value <= chunk_max)
			pb(a, b);
		else
			
	}
}
