/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:49:48 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/05 15:55:02 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/srcs/ft_printf.h"

t_list	*get_node_list(long long *num, int len)
{
	long long	*first_n;
	t_list		*final;
	t_list		**final_pointer;
	int			i;
	long long	*tmp_n;

	first_n = &num[0];
	final = ft_lstnew(first_n);
	final_pointer = &final;
	i = 1;
	while (i < len)
	{
		tmp_n = &num[i];
		ft_lstadd_back(final_pointer, ft_lstnew(tmp_n));
		i++;
	}
	return (final);
}

void	print_node_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%lld -> ", *(long long *)tmp->content);
		tmp = tmp-> next;
	}
	printf("NULL\n");
}
