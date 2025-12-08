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

int	min_val(t_list	**a)
{
	int		i;
	int		pos;
	int		val;
	t_list	*tmp;

	if (a == NULL || *a == NULL)
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

t_liste	simplealg(t_list	**a, t_list	**b)
{
	int	size;
	int	i;

	while (*a == NULL)
	{
		i = min_val(a);
		if (i == 0)
			pb(a, b);
		else
		{
			size = ft_lstsize(a) / 2;
			while (i != 0 || i != (ft_lstsize(a) + 1))
			{
				if (i >= size)
				{
					rra(a);
					i++;
				}
				else
				{
					ra(a);
					i--;
				}
			}
			pb(a, b);
		}
	}
	while (*b == NULL)
		pa(a, b);
}

