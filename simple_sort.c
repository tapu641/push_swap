#include "push_swap.h"

static int find_min_index(t_stack *stack)
{
	t_list *current;
	int min_index;
	int min_val;
	int index;

	//ポインタコピーする（stackを動かすとtopが変わるため）
	current = stack->top;
	min_val = current->value;
	min_index = 0;
	index = 0;
	while(current)
	{
		//最小値見つけ次第更新
		if (min_val > current->value)
		{
			min_val = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}
//raとrraどちらのほうがいいかチェック
static void rotate_to_top(t_stack *stack, int min_index, t_options *opt)
{
	int i;

	i = 0;
	//[3,1,4,2](連結リストを配列と見立てる)←この場合、左シフト(ra)した方が早い
	if ((stack->size / 2) >= min_index)
	{
		while(i < min_index)
		{
			ra(stack, 1, opt);
			i++;
		}
	}
	else //[3,2,4,1]←この場合、右シフト(rra)した方が早い
	{
		while(i < stack->size - min_index)
		{
			rra(stack, 1, opt);
			i++;
		}
	}
}
void simple_sort(t_stack *a, t_stack *b, t_options *opt)
{
	int min_index;
	//スタックaを降順でスタックbに並ぶように、最小値を見つけたらbへ送る
	while(a->size > 0)
	{
		min_index = find_min_index(a);
		rotate_to_top(a, min_index, opt);
		pb(a, b, opt);
	}

	//全部スタックaに戻す
	while (b->top)
		pa(a, b, opt);
}
