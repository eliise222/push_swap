/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:18:00 by elise             #+#    #+#             */
/*   Updated: 2025/12/19 13:29:08 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	sa(t_list	**stack_a, t_bench benchmark)
{
	*stack_a = reversenode(*stack_a);
	write(1, "sa\n", 3);
	if(benchmark.is_active == 1)
		benchmark.sa ++;
}

void	sb(t_list	**stack_b, t_bench benchmark)
{
	*stack_b = reversenode(*stack_b);
	write(1, "sb\n", 3);
	if(benchmark.is_active == 1)
		benchmark.sb ++;
}

void	ss(t_list	**stack_a, t_list	**stack_b, t_bench benchmark)
{
	*stack_a = reversenode(*stack_a);
	*stack_b = reversenode(*stack_b);
	write(1, "ss\n", 3);
	if(benchmark.is_active == 1)
		benchmark.ss ++;
}
