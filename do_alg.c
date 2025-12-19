/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:20:41 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/19 13:20:13 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	do_simple( char **args, int start, int len, t_bench benchmark)
{
	t_list	*list_b;
	t_list	*list_a;

	list_a = get_list_a(args, start, len);
	list_b = NULL;
	simplealg(&list_a, &list_b, benchmark);
	free_linked_list(list_a);
	free_linked_list(list_b);
}

void	do_medium( char **args, int start, int len, t_bench benchmark)
{
	t_list	*list_b;
	t_list	*list_a;

	list_a = get_list_a(args, start, len);
	list_b = NULL;
	medium_alg(&list_a, &list_b, benchmark);
	free_linked_list(list_a);
	free_linked_list(list_b);
}

void	do_complex( char **args, int start, int len, t_bench benchmark)
{
	t_list	*list_b;
	t_list	*list_a;

	list_a = get_list_a(args, start, len);
	list_b = NULL;
	medium_alg(&list_a, &list_b, benchmark);
	free_linked_list(list_a);
	free_linked_list(list_b);
}
