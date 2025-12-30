/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:23:43 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/30 13:52:52 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	tiny_alg_2(t_list **list, t_bench *benchmark)
{
	if ((*list)->content > (*list)->next->content)
		sa(list, benchmark);
}

void	tiny_alg_3(t_list **list, t_bench *benchmark)
{
	t_list	*last;

	last = ft_lstlast(*list);
	if ((*list)->content < (*list)->next->content
		&& (*list)->content > last->content)
		rra(list, benchmark);
	else if ((*list)->content > (*list)->next->content
		&& (*list)->content < last->content)
		sa(list, benchmark);
	else if (last->content < (*list)->content
		&& last->content > (*list)->next->content)
		ra(list, benchmark);
	else if (last->content > (*list)->content
		&& last->content < (*list)->next->content)
	{
		sa(list, benchmark);
		ra(list, benchmark);
	}
	else if ((*list)->next->content < (*list)->content
		&& (*list)->next->content > last->content)
	{
		sa(list, benchmark);
		rra(list, benchmark);
	}
}

void	tiny_sort(t_list **list_a, t_list **list_b, t_bench *benchmark)
{
	put_min_in_b(list_a, list_b, benchmark);
	put_min_in_b(list_a, list_b, benchmark);
	if (ft_lstsize(*list_a) == 2)
		tiny_alg_2(list_a, benchmark);
	else if (ft_lstsize(*list_a) == 3)
		tiny_alg_3(list_a, benchmark);
	pa(list_a, list_b, benchmark);
	pa(list_a, list_b, benchmark);
}
