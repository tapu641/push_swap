#include "push_swap.h"

void five_sort(t_stack *a, t_stack *b, t_options *opt)
{
    rotate_to_top(a, find_min_index(a));
    pb(a, b, opt);
    rotate_to_top(a, find_min_index(a));
    pb(a, b, opt);
    three_sort(a);
    pa(a, b, opt);
    pa(a, b, opt);
}