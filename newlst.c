/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:49:48 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/07 18:53:13 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/srcs/ft_printf.h"
#include "push_swap.h"

t_list	*get_node_list(int *num, int len)
{
	int		*first_n;
	t_list	*final;
	t_list	**final_pointer;
	int		i;
	int		*tmp_n;

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
		printf("%d -> ", *(int *)tmp->content);
		tmp = tmp-> next;
	}
	printf("NULL\n");
}
