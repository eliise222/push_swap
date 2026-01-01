/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:20:41 by srezzaq           #+#    #+#             */
/*   Updated: 2026/01/01 23:26:14 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	do_simple( char **args, int start, int len, t_bench *benchmark)
{
	t_list	*list_b;
	t_list	*list_a;
	int		list_size;
	int		*copy_list;

	copy_list = NULL;
	list_a = get_list_a(args, start, len);
	list_b = NULL;
	list_size = ft_lstsize(list_a);
	if (list_size > 1 && disorder(&list_a, ft_lstsize(list_a), copy_list) > 0)
	{
		if (list_size == 2)
			tiny_alg_2(&list_a, benchmark);
		else if (list_size == 3)
			tiny_alg_3(&list_a, benchmark);
		else if (list_size == 4 || list_size == 5)
			tiny_sort(&list_a, &list_b, benchmark);
		else
			simplealg(&list_a, &list_b, benchmark);
	}
	free_linked_list(list_a);
	free_linked_list(list_b);
}

void	do_medium( char **args, int start, int len, t_bench *benchmark)
{
	t_list	*list_b;
	t_list	*list_a;
	int		list_size;
	int		*copy_list;

	copy_list = NULL;
	list_a = get_list_a(args, start, len);
	list_b = NULL;
	list_size = ft_lstsize(list_a);
	if (list_size > 1 && disorder(&list_a, ft_lstsize(list_a), copy_list) > 0)
	{
		if (list_size == 2)
			tiny_alg_2(&list_a, benchmark);
		else if (list_size == 3)
			tiny_alg_3(&list_a, benchmark);
		else if (list_size == 4 || list_size == 5)
			tiny_sort(&list_a, &list_b, benchmark);
		else
			chunksort(&list_a, &list_b, benchmark);
	}
	free_linked_list(list_a);
	free_linked_list(list_b);
}

void	do_complex( char **args, int start, int len, t_bench *benchmark)
{
	t_list	*list_b;
	t_list	*list_a;
	int		list_size;
	int		*copy_list;

	copy_list = NULL;
	list_a = get_list_a(args, start, len);
	list_b = NULL;
	list_size = ft_lstsize(list_a);
	if (list_size > 1 && disorder(&list_a, ft_lstsize(list_a), copy_list) > 0)
	{
		if (list_size == 2)
			tiny_alg_2(&list_a, benchmark);
		else if (list_size == 3)
			tiny_alg_3(&list_a, benchmark);
		else if (list_size == 4 || list_size == 5)
			tiny_sort(&list_a, &list_b, benchmark);
		else
		{
			assign_index(&list_a);
			radix_sort(&list_a, &list_b, benchmark);
		}
	}
	free_linked_list(list_a);
	free_linked_list(list_b);
}
