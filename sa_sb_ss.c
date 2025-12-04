/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:18:00 by elise             #+#    #+#             */
/*   Updated: 2025/12/04 22:39:35 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include "libft/libft.h"

void	sa(t_list	**stack_a)
{
	*stack_a = reversenode(*stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list	**stack_b)
{
	*stack_b = reversenode(*stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list	**stack_a, t_list	**stack_b)
{
	*stack_a = reversenode(*stack_a);
	*stack_b = reversenode(*stack_b);
	write(1, "ss\n", 3);
}
