/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:01:19 by elise             #+#    #+#             */
/*   Updated: 2025/12/05 14:01:20 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rra(t_list	**a)
{
	reverse_all(*a);
	write(1, "rra\n", 4);
}

void	rrb(t_list	**b)
{
	reverse_all(*b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list	**a)
{
	reverse_all(*a);
	write(1, "rrr\n", 4);
}
