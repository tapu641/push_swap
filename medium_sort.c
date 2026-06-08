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

