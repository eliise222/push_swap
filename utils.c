/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:08:59 by elise             #+#    #+#             */
/*   Updated: 2025/12/23 16:05:08 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

t_list	*reversenode(t_list	*a)
{
	t_list	*temp;
	t_list	*b;

	if (a == NULL || a->next == NULL)
		return (a);
	b = a->next;
	temp = b->next;
	b->next = a;
	a->next = temp;
	return (b);
}

int	display_instr(void)
{
	return (1);
}

void	reverse_all(t_list	**a)
{
	t_list	*last;
	t_list	*blast;

	blast = *a;
	if (*a == NULL || (*a)->next == NULL || a == NULL)
		return ;
	while (blast->next->next != NULL)
		blast = blast->next;
	last = blast->next;
	last->next = *a;
	blast->next = NULL;
	*a = last;
}
