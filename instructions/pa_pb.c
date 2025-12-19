/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:39:03 by elise             #+#    #+#             */
/*   Updated: 2025/12/08 17:03:05 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"
#include "../libft/libft.h"

void	pb(t_list	**a, t_list	**b)
{
	t_list	*temp;

	if (a == NULL || *a == NULL || b == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
    if (display_instr == 1)
	    write(1, "pb\n", 3);
}

void	pa(t_list	**a, t_list	**b)
{
	t_list	*temp;

	if (b == NULL || *b == NULL || a == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
    if (display_instr == 1)
	    write(1, "pa\n", 3);
}
