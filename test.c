/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:46:51 by elise             #+#    #+#             */
/*   Updated: 2026/01/01 23:38:01 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_range(int size)
{
	if (size <= 100)
		return (size / 5);
	return (size / 11);
}

int	max_val1(t_list **b)
{
	int		i;
	int		pos;
	int		val;
	t_list	*tmp;

	if (!b || !*b)
		return (-1);
	tmp = *b;
	i = 0;
	pos = 0;
	val = tmp->index;
	while (tmp != NULL)
	{
		if (val < tmp->index)
		{
			val = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	put_max_in_a(t_list **a, t_list **b, t_bench *benchmark)
{
	int	i;
	int	size;

	i = max_val1(b);
	size = ft_lstsize(*b);
	if (i <= size / 2)
	{
		while (i > 0)
		{
			rb(b, benchmark);
			i--;
		}
	}
	else
	{
		while (i < size)
		{
			rrb(b, benchmark);
			i++;
		}
	}
	pa(a, b, benchmark);
}

void	chunksort(t_list **a, t_list **b, t_bench *benchmark)
{
	int	i;
	int	range;

	i = 0;
	range = get_range(ft_lstsize(*a));
	assign_index(a);
	while (*a != NULL)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, benchmark);
			if (i != 0)
				rb(b, benchmark);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b, benchmark);
			i++;
		}
		else
			ra(a, benchmark);
	}
	while (*b != NULL)
		put_max_in_a(a, b, benchmark);
}
