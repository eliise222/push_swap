/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_number_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:36:50 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/11 17:37:38 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	*copy_and_sort_list(t_list	*a, int size)
{
	int		*soretd_list;
	int		i;
	t_list	*tmp;

	soretd_list = malloc(sizeof(int) * (size));
	if (!soretd_list)
		return (NULL);
	i = 0;
	tmp = a;
	while (tmp != NULL)
	{
		soretd_list[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	sort(soretd_list, size);
	return (soretd_list);
}

int	*fill_part(int size, int *sorted_list, int *y)
{
	int	*chunk_part;
	int	i;

	chunk_part = malloc(sizeof(int) * (size));
	if (!chunk_part)
		return (NULL);
	i = 0;
	while (i < size)
	{
		chunk_part[i] = sorted_list[*(int *)y];
		(*y)++;
		i++;
	}
	return (chunk_part);
}

int	**split_chunks(int size, int *sorted_list)
{
	int	**all_chunks;
	int	chunk_size;
	int	j;
	int	y;
	int	*chunk_part;

	chunk_size = ft_sqrt(size);
	all_chunks = malloc(sizeof(int *) * (ft_ceil(size, chunk_size)));
	if (!all_chunks)
		return (NULL);
	j = 0;
	y = 0;
	while (j < size / chunk_size)
	{
		chunk_part = fill_part(chunk_size, sorted_list, &y);
		all_chunks[j] = chunk_part;
		j++;
	}
	if (size % chunk_size != 0)
	{
		chunk_part = fill_part(size % chunk_size, sorted_list, &y);
		all_chunks[j] = chunk_part;
	}
	return (all_chunks);
}

int	**virtual_list(t_list *a)
{
	int	size;
	int	*sorted_list;
	int	**all_chunks;

	size = ft_lstsize(a);
	sorted_list = copy_and_sort_list(a, size);
	all_chunks = split_chunks(size, sorted_list);
	free(sorted_list);
	return (all_chunks);
}
