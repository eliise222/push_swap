/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:00:36 by elise             #+#    #+#             */
/*   Updated: 2026/01/01 00:38:51 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

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
		tmp->index = (ft_lstsize(*a) - 1) - get_sup_num(a, tmp);
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
	max = count_nb(size);
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

void	display_disorder_only(double dis)
{
	int	disorder;
	int	int_part;
	int	fract_part;

	disorder = dis * 10000;
	int_part = disorder / 100;
	fract_part = disorder % 100;
	ft_printf(2, "[bench] disorder: %d.", int_part);
	if (fract_part < 10)
		ft_printf(2, "0");
	ft_printf(2, "%d%%\n", fract_part);
}
