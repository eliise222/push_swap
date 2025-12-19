/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:39:03 by elise             #+#    #+#             */
/*   Updated: 2025/12/19 13:04:54 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"
#include "../libft/libft.h"

void	pb(t_list	**a, t_list	**b, t_bench benchmark)
{
	t_list	*temp;

	if (a == NULL || *a == NULL || b == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
	if(benchmark.is_active == 1)
		benchmark.pb ++;
}

void	pa(t_list	**a, t_list	**b, t_bench benchmark)
{
	t_list	*temp;

	if (b == NULL || *b == NULL || a == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
	if(benchmark.is_active == 1)
		benchmark.pa ++;
}
