/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:49:48 by srezzaq           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/12/18 19:35:38 by srezzaq          ###   ########.fr       */
=======
/*   Updated: 2025/12/17 18:35:24 by srezzaq          ###   ########.fr       */
>>>>>>> dc3d0e0b5380b4e2f30a2bf2840d8ce39d6d476d
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/srcs/ft_printf.h"
#include "push_swap.h"

t_list	*get_node_list(int *num, int len)
{
	int		first_n;
	t_list	*final;
	t_list	**final_pointer;
	int		i;
	int		tmp_n;

	first_n = num[0];
	final = ft_lstnew(first_n);
	final_pointer = &final;
	i = 1;
	while (i < len)
	{
		tmp_n = num[i];
		ft_lstadd_back(final_pointer, ft_lstnew(tmp_n));
		i++;
	}
	free(num);
	return (final);
}

void	print_node_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->content);
		tmp = tmp-> next;
	}
	printf("NULL\n");
}

t_list	*get_list_a(char **args, int start, int len)
{
	int		*num_list;
	char	**copy_list;
	int		len_list_a;
	t_list	*list_a;

	list_a = NULL;
	copy_list = copy_argv_offset(args, start, len);
	len_list_a = list_len(copy_list);
	num_list = parsing(copy_list);
	list_a = get_node_list(num_list, len_list_a);
	return (list_a);
}

void	free_linked_list(t_list *list)
{
	t_list	*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

int	list_len(char **resul)
{
	int	i;

	if (!resul)
		return (0);
	i = 0;
	while (resul[i])
	{
		i++;
	}
	return (i);
}
