#include "push_swap.h"

void three_sort(t_stack *a)
{
    int top;
    int mid;
    int bot;

    top = a->top->value;
    mid = a->top->next->value;
    bot = a->top->next->next->value;
    if (top < mid && mid < bot)
        return;
    else if (top < mid && mid > bot && top < bot)
    {
        rra(a, 1);
        sa(a, 1);
    }
    else if (top > mid && mid < bot && top < bot)
        sa(a, 1);
    else if (top < mid && mid > bot && top > bot)
        rra(a, 1);
    else if (top > mid && mid < bot && top > bot)
        ra(a, 1);
    else
    {
        sa(a, 1);
        rra(a, 1);
    }
}