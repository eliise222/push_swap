/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:48:43 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/11 19:13:47 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	medium_alg(t_list **a, t_list **b)
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
		put_chunk_in_b(list[i], chunk_size, a, b);
		free(list[i]);
		i++;
	}
	if (size % chunk_size != 0)
	{
		put_chunk_in_b(list[i], size % chunk_size, a, b);
		free(list[i]);
	}
	free(list);
	put_in_a(a, b);
}
