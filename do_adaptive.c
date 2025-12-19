/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:49:04 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/19 17:24:02 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	*list_copy(t_list **list)
{
	int		*copy_list;
	int		copylist_size;
	t_list	*tmp;
	int		i;

	tmp = *list;
	copylist_size = ft_lstsize(*list);
	i = 0;
	copy_list = malloc(sizeof(int) * (copylist_size));
	if (!copy_list)
		return (NULL);
	while (tmp != NULL)
	{
		copy_list[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	return (copy_list);
}

double	disorder(t_list **list_a, int size, int *copy_list)
{
	long	mistakes;
	long	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	copy_list = list_copy(list_a);
	if (size < 2)
	{
		free(copy_list);
		return (0.0);
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (copy_list[i] > copy_list[j])
				mistakes++;
			j++;
		}
		i++;
	}
	free(copy_list);
	return ((double)mistakes / (double)total_pairs);
}

void	do_adaptive(char **args, int start, int len, t_bench *benchmark)
{
	double	dis;
	int		*copy_list;
	t_list	*list_b;
	t_list	*list_a;

	copy_list = NULL;
	list_a = get_list_a(args, start, len);
	list_b = NULL;
	dis = disorder(&list_a, ft_lstsize(list_a), copy_list);
	if(dis == 0.0)
	{
		exit(0);
	}
	if (dis < 0.2)
	{
		simplealg(&list_a, &list_b, benchmark);
	}
	else if (0.2 <= dis && dis < 0.5)
	{
		medium_alg(&list_a, &list_b, benchmark);
	}
	else if (dis >= 0.5)
	{
		medium_alg(&list_a, &list_b, benchmark);
	}
	free_linked_list(list_a);
	free_linked_list(list_b);
}
