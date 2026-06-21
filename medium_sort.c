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

// [100, 3, 25, -12]を[3,1,2,0]と順位順に見立てる
// 1,元の値を配列に保存
static int	*save_originals(t_stack *a)
{
	int		*orig;
	t_list	*cur;
	int		i;

	orig = malloc(sizeof(int) * a->size);
	if (!orig)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	cur = a->top;
	i = 0;
	while (cur)
	{
		orig[i] = cur->value;
		cur = cur->next;
		i++;
	}
	return (orig);
}
// 2,1つのノードの順位を計算
static int	calc_rank(int *orig, int size, int i)
{
	int	rank;
	int	j;

	rank = 0;
	j = 0;
	while (j < size)
	{
		if (orig[j] < orig[i])
			rank++;
		j++;
	}
	return (rank);
}

// 関数3: 順位を割り当てる
void	compress(t_stack *a)
{
	int		*orig;
	t_list	*cur;
	int		i;

	orig = save_originals(a);
	cur = a->top;
	i = 0;
	while (cur)
	{
		cur->value = calc_rank(orig, a->size, i);
		cur = cur->next;
		i++;
	}
	free(orig);
}

void push_chunks(t_stack *a, t_stack *b)
{
    int chunk_size;
    int chunk_max;
    int ra_count;

    chunk_size = my_sqrt(a->size);
    chunk_max  = chunk_size - 1;
    while (a->size > 0)
    {
        ra_count = 0;
        while (ra_count < a->size)
        {
            if (a->top->value <= chunk_max)
            {
                pb(a, b);
                ra_count = 0;  // pbしたらリセット
            }
            else
            {
                ra(a, 1);
                ra_count++;
            }
        }
        // 次のチャンクへ
        chunk_max += chunk_size;
    }
}

void push_back(t_stack *a, t_stack *b)
{
    int max_index;

    while (b->size > 0)
    {
        max_index = find_max_index(b);
        rotate_to_top(b, max_index);
        pa(a, b);
    }
}

void medium_sort(t_stack *a, t_stack *b)
{
    compress(a);        //座標圧縮
    push_chunks(a, b);  //チャンクごとにbへ
    push_back(a, b);    //bから最大値順にaへ
}
