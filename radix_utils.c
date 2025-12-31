/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:00:36 by elise             #+#    #+#             */
/*   Updated: 2025/12/31 23:12:52 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_sup_num(t_list **a, t_list *node)
{
	int		count;
	t_list	*tmp;

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

void	assign_index(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		tmp->index = ft_lstsize(*a) - get_sup_num(a, tmp);
		tmp = tmp->next;
	}
}

int	count_nb(int a)
{
	int	i;

	i = 1;
	while (a / 2)
	{
		i++;
		a /= 2;
	}
	return (i);
}

void	radix_sort(t_list **a, t_list **b, t_bench *benchmark)
{
	int		i;
	int		j;
	int		size;
	int		max;
	t_list	*head;

	i = 0;
	size = ft_lstsize(*a);
	max = count_nb(size - 1);
	while (i < max)
	{
		j = 0;
		while (j < size)
		{
			head = *a;
			if (((head->index >> i) & 1) == 0)
				pb(a, b, benchmark);
			else
				ra(a, benchmark);
			j++;
		}
		while (*b)
			pa(a, b, benchmark);
		i++;
	}
}

int main()
{
	t_list	*a;
	t_list	*b;
	t_list	benchmark;
	t_list	*curr;
	int	value[] = {42, 1, 25, 36, 76, 3, 998, 74732, 2763,827, 342};
	int	i;

	a == NULL;
	b == NULL;
	benchmark = 0;
	i = 0;
	while(i < 11)
	{
		ft_lstadd_back(&a, ft_lstnew(value[i]));
		i++;
	}
	assign_index(&a);
	curr = a;
	printf("before :");
	while(curr)
	{
		printf("%d", curr->content);
		curr = curr->next;
	}
	printf("\n");

	radix_sort(&a, &b, &benchmark);

	curr = a;
	printf("after: ");
	while(curr)
	{
		printf("%d", curr->content);
		curr = curr->next;
	}
	printf("\ntotal operations: %d\n", benchmark);
	return (0);
}

