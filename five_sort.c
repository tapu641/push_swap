#include "push_swap.h"

void five_sort(t_stack *a, t_stack *b)
{
    rotate_to_top(a, find_min_index(a));
    pb(a, b);
    rotate_to_top(a, find_min_index(a));
    pb(a, b);
    three_sort(a);
    pa(a, b);
    pa(a, b);
}