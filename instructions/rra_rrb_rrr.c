/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:01:19 by elise             #+#    #+#             */
/*   Updated: 2025/12/08 15:11:23 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	rra(t_list	**a)
{
	reverse_all(a);
	if (display_instr == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list	**b)
{
	reverse_all(b);
	if (display_instr == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list	**a, t_list	**b)
{
	reverse_all(a);
	reverse_all(b);
	if (display_instr == 1)
		write(1, "rrr\n", 4);
}
