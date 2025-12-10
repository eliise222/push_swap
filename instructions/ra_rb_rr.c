/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:59:30 by elise             #+#    #+#             */
/*   Updated: 2025/12/05 14:00:19 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

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

void	rb(t_list	**b)
{
	rarb(b);
	write(1, "rb\n", 3);
}

void	ra(t_list	**a)
{
	rarb(a);
	write(1, "ra\n", 3);
}

void	rr(t_list	**a, t_list	**b)
{
	rarb(a);
	rarb(b);
	write(1, "rr\n", 3);
}
