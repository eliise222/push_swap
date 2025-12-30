/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:48:43 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/30 13:22:12 by srezzaq          ###   ########.fr       */
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
		put_chunk_in_b(list[i], a, b, benchmark);
		free(list[i]);
		i++;
	}
	if (size % chunk_size != 0)
	{
		put_remainder_in_b(list[i], a, b, benchmark);
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

void	put_remainder_in_b(int *list, t_list **a, t_list **b, t_bench *be)
{
	int	i;
	int	up_chunk;
	int	down_chunk;
	int	chunk_size;
	int	size;

	size = ft_lstsize(*a);
	chunk_size = size % ft_sqrt(size);
	i = 0;
	while (i < chunk_size)
	{
		up_chunk = search_chunk_element(a, &list[0], chunk_size);
		down_chunk = reverse_search_chunk_element(a, &list[0], chunk_size);
		if (up_chunk == INT_MAX)
			break ;
		if (up_chunk < down_chunk)
			repeat_ra(up_chunk, a, be);
		else
			repeat_rra(down_chunk, a, be);
		pb(a, b, be);
		if (*b && (*b)->next && (*b)->content < list[chunk_size / 2])
			rb(b, be);
		i++;
	}
}
