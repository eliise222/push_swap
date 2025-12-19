/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:01:19 by elise             #+#    #+#             */
/*   Updated: 2025/12/19 13:49:49 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	rra(t_list	**a, t_bench benchmark)
{
	reverse_all(a);
	if(benchmark.is_active == 1)
		benchmark.rra ++;
	if (display_instr == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list	**b, t_bench benchmark)
{
	reverse_all(b);
	if(benchmark.is_active == 1)
		benchmark.rrb ++;
	if (display_instr == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list	**a, t_list	**b, t_bench benchmark)
{
	reverse_all(a);
	reverse_all(b);
	if(benchmark.is_active == 1)
		benchmark.rrr ++;
	if (display_instr == 1)
		write(1, "rrr\n", 4);
}
