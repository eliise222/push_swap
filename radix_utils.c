#include "push_swap.h"

int get_sup_num(t_list **a, t_list *node)
{
	int count;
	t_list *tmp;

	count = 0;
	tmp = *a;

	while (tmp != NULL)
	{
		if (tmp != node)
		{
			if (tmp->content > node->content)
				count++;
		}
		tmp = tmp->next;
	}
	return (count);
}

void    assign_index(t_list **a)
{
    int	index;
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		tmp->index = ft_lstsize(*a) - get_sup_num(a, tmp);
		tmp = tmp->next;
	}
}