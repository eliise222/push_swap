/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:49:04 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/23 21:13:14 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
	t_list	*list_a;

	copy_list = NULL;
	list_a = get_list_a(args, start, len);
	dis = disorder(&list_a, ft_lstsize(list_a), copy_list);
	free_linked_list(list_a);
	if (dis < 0.2)
	{
		do_simple(args, start, len, benchmark);
	}
	else if (0.2 <= dis && dis < 0.5)
	{
		do_medium(args, start, len, benchmark);
	}
	else if (dis >= 0.5)
	{
		do_complex(args, start, len, benchmark);
	}
}
