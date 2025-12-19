/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:18:00 by elise             #+#    #+#             */
/*   Updated: 2025/12/07 18:07:50 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	sa(t_list	**stack_a)
{
	*stack_a = reversenode(*stack_a);
	if (display_instr == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list	**stack_b)
{
	*stack_b = reversenode(*stack_b);
	if (display_instr == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list	**stack_a, t_list	**stack_b)
{
	*stack_a = reversenode(*stack_a);
	*stack_b = reversenode(*stack_b);
	if (display_instr == 1)
		write(1, "ss\n", 3);
}
