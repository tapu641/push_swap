#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int     *data;   // data[0]を先頭としてみる
    int     size;    // 現在の要素数
    int     max;     // 最大サイズ
}   t_stack;


# include <limits.h> //INT_MIN,INT_MAX
# include <stdlib.h> //malloc,free,exit
# include <unistd.h>    // write
#endif
