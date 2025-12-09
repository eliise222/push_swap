/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplealg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:26:40 by elise             #+#    #+#             */
/*   Updated: 2025/12/05 16:03:34 by elise            ###   ########.fr       */
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
	val = *(int *)(tmp->content);
	while (tmp != NULL)
	{
		if (val > *(int *)(tmp->content))
		{
			val = *(int *)(tmp->content);
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	printf("\npos = %d\n", pos);
	return (pos);
}

void	simplealg(t_list	**a, t_list	**b)
{
	int	size;
	int	i;

	while (*a)
	{
		i = min_val(a);
		size = ft_lstsize(*a);
		// if (i == 0)
		// 	pb(a, b);
		if (i <= size / 2)
		{
			while ( i > 0 )
			{
				ra(a);
				i--;
			}
		}
		else
		{
			while (i < size)
			{
				rra(a);
				i++;
			}
		}
		pb(a, b);
	}
	while (*b != NULL)
		pa(a, b);
}

