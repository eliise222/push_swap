/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplealg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:26:40 by elise             #+#    #+#             */
/*   Updated: 2025/12/19 16:15:23 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	min_val(t_list	**a)
{
	int		i;
	int		pos;
	int		val;
	t_list	*tmp;

	if (!a || !*a)
		return (-1);
	tmp = *a;
	i = 0;
	pos = 0;
	val = tmp->content;
	while (tmp != NULL)
	{
		if (val > tmp->content)
		{
			val = tmp->content;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	simplealg(t_list	**a, t_list	**b, t_bench *benchmark)
{
	int	size;
	int	i;

	while (*a)
	{
		i = min_val(a);
		size = ft_lstsize(*a);
		if (i <= size / 2)
		{
			while ( i > 0 )
			{
				ra(a, benchmark);
				i--;
			}
		}
		else
		{
			while (i < size)
			{
				rra(a, benchmark);
				i++;
			}
		}
		pb(a, b, benchmark);
	}
	while (*b != NULL)
		pa(a, b, benchmark);
}

