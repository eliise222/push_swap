/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_medium_alg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:45:54 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/19 16:16:02 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	reverse_search_chunk_element(t_list **a, int *chunk, int size)
{
	t_list	*tmp;
	int		i;
	int		last_found_pos;
	int		lst_size;

	tmp = *a;
	i = 0;
	last_found_pos = -1;
	while (tmp != NULL)
	{
		if (is_in(tmp->content, chunk, size))
			last_found_pos = i;
		tmp = tmp->next;
		i++;
	}
	if (last_found_pos == -1)
		return (INT_MAX);
	lst_size = ft_lstsize(*a);
	return (lst_size - last_found_pos);
}

int	search_chunk_element(t_list **a, int *chunk, int size)
{
	t_list	*tmp1;
	int		i1;

	i1 = 0;
	tmp1 = *a;
	while (tmp1 != NULL)
	{
		if (is_in(tmp1->content, chunk, size))
		{
			break ;
		}
		i1++;
		tmp1 = tmp1->next;
	}
	if (tmp1 == NULL)
		return (INT_MAX);
	return (i1);
}

void	repeat_ra(int chunk, t_list **a, t_bench *benchmark)
{
	int	i;

	i = 0;
	while (i < chunk)
	{
		ra(a, benchmark);
		i++;
	}
}

void	repeat_rra(int chunk, t_list	**a, t_bench *benchmark)
{
	int	i;

	i = 0;
	while (i < chunk)
	{
		rra(a, benchmark);
		i++;
	}
}

void	put_chunk_in_b(int *list, int chunk_size, t_list **a, t_list **b, t_bench *benchmark)
{
	int	i;
	int	up_chunk;
	int	down_chunk;

	i = 0;
	while (i < chunk_size)
	{
		up_chunk = search_chunk_element(a, &list[0], chunk_size);
		down_chunk = reverse_search_chunk_element(a, &list[0], chunk_size);
		if (up_chunk == INT_MAX)
			break ;
		if (up_chunk < down_chunk)
		{
			repeat_ra(up_chunk, a, benchmark);
		}
		else
		{
			repeat_rra(down_chunk, a, benchmark);
		}
		pb(a, b, benchmark);
		if (*b && (*b)->next && (*b)->content < list[chunk_size / 2])
			rb(b, benchmark);
		i++;
	}
}
