/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:48:43 by srezzaq           #+#    #+#             */
/*   Updated: 2026/01/01 19:22:21 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	medium_alg(t_list **a, t_list **b, t_bench *benchmark)
{
	int	**list;
	int	size;
	int	chunk_size;
	int	i;

	list = virtual_list(*a);
	size = ft_lstsize(*a);
	chunk_size = ft_sqrt(size);
	i = 0;
	while (i < size / chunk_size)
	{
		put_chunk_in_b(list[i], chunk_size, a, b, benchmark);
		free(list[i]);
		i++;
	}
	if (size % chunk_size != 0)
	{
		put_chunk_in_b(list[i], size % chunk_size, a, b, benchmark);
		free(list[i]);
	}
	free(list);
	put_in_a(a, b, benchmark);
}

void	put_in_a(t_list	**a, t_list **b, t_bench *benchmark)
{
	int	size;
	int	i;

	while (*b)
	{
		i = max_val(b);
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
}
