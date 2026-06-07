#include "push_swap.h"

//ノード作成
t_list *node_new(int value)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	node->value = value;
	node->next = NULL;
	return (node);
}

// ノードを先頭にする
void push_front(t_list **head, t_list *node)
{
	if (!head || !node)
		return ;
	node->next = *head;
	*head = node;
}

// 先頭から削除して返す
t_list *pop_front(t_list **head)
{
    t_list *tmp;

    if (!head || !(*head))
        return (NULL);
    tmp = *head;
    *head = (*head)->next;
    return (tmp);
}


