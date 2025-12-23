/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:00:36 by elise             #+#    #+#             */
/*   Updated: 2025/12/23 21:10:26 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
