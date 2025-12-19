/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:59:30 by elise             #+#    #+#             */
/*   Updated: 2025/12/19 13:06:31 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"
#include "../libft/libft.h"

static void	rarb(t_list	**a)
{
	t_list	*temp;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = temp;
	temp->next = NULL;
}

void	rb(t_list	**b, t_bench benchmark)
{
	rarb(b);
	write(1, "rb\n", 3);
	if(benchmark.is_active == 1)
		benchmark.rb ++;
}

void	ra(t_list	**a, t_bench benchmark)
{
	rarb(a);
	write(1, "ra\n", 3);
	if(benchmark.is_active == 1)
		benchmark.ra ++;
}

void	rr(t_list	**a, t_list	**b, t_bench benchmark)
{
	rarb(a);
	rarb(b);
	write(1, "rr\n", 3);
	if(benchmark.is_active == 1)
		benchmark.rr ++;
}
