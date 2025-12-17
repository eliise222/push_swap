/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:56:08 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/11 21:35:53 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/srcs/ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*str;
	int		*num;
	int		len;
	t_list	*list_a = NULL;
	t_list	*list_b = NULL;
	//int		*val_b;

	str = "38 -213 12 66 -12a0 45 259 1 7854 -5 23658 -125 -458 77 99 11 -212 2";
	num = parsing(str);
	if(!num)
	{
		error();
		return(-1);
	}
	char **sp = get_list(str);
	len = list_len(sp);
	int i = 0;
	while (i < list_len(sp))
	{
		free(sp[i]);
		i++;
	}
	free(sp);
	//int i = 0;
	//while(i < len)
	//{
	//	printf("%d -\n", num[i]);
	//	i++;
	//}
	list_a = get_node_list(num, len);

	// printf("liste avant a \n");
	// print_node_list(list_a);
	// simplealg(&list_a, &list_b);
	// printf("\nlist a apres simple algo\n");
	// print_node_list(list_a);

	//medium_alg(&list_a, &list_b);

	printf("liste avant a \n");
	print_node_list(list_a);
	printf("liste avant b \n");
	print_node_list(list_b);
	medium_alg(&list_a, &list_b);
	printf("\nlist a apres medium algo\n");
	print_node_list(list_a);
	printf("\nlist b apres medium algo\n");
	print_node_list(list_b);


	//printf("\n----------------------------RA----------------------------");
	//printf("\nliste a avant ra\n");
	//print_node_list(list_a);
	//ra(&list_a);
	//printf("\nliste a apres ra\n");
	//print_node_list(list_a);

	//printf("\n----------------------------RB----------------------------");
	//printf("\nliste b avant rb\n");
	//print_node_list(list_b);
	//rb(&list_b);
	//printf("\nliste b apres rb\n");
	//print_node_list(list_b);


	//printf("\n----------------------------RR----------------------------");
	//printf("\nliste a avant rr\n");
	//print_node_list(list_a);
	//printf("\nliste b avant rr\n");
	//print_node_list(list_b);
	//rr(&list_a, &list_b);
	//printf("\nliste a apres rr\n");
	//print_node_list(list_a);
	//printf("\nliste b apres rr\n");
	//print_node_list(list_b);

	//printf("\n----------------------------SA----------------------------");
	//printf("\nliste a avant sa\n");
	//print_node_list(list_a);
	//sa(&list_a);
	//printf("\nliste a apres sa\n");
	//print_node_list(list_a);

	//printf("\n----------------------------SB----------------------------");
	//printf("\nliste b avant sb\n");
	//print_node_list(list_b);
	//sb(&list_b);
	//printf("\nliste b apres sb\n");
	//print_node_list(list_b);

	//printf("\n----------------------------SS----------------------------");
	//printf("\nliste a avant ss\n");
	//print_node_list(list_a);
	//printf("\nliste b avant ss\n");
	//print_node_list(list_b);
	//ss(&list_a, &list_b);
	//printf("\nliste a apres ss\n");
	//print_node_list(list_a);
	//printf("\nliste b apres ss\n");
	//print_node_list(list_b);

	//printf("\n----------------------------RRA----------------------------");
	//printf("\nliste a avant rra\n");
	//print_node_list(list_a);
	//rra(&list_a);
	//printf("\nliste a apres rra\n");
	//print_node_list(list_a);

	//printf("\n----------------------------RRB----------------------------");
	//printf("\nliste b avant rrb\n");
	//print_node_list(list_b);
	//rrb(&list_b);
	//printf("\nliste b apres rrb\n");
	//print_node_list(list_b);


	//printf("\n----------------------------RRR----------------------------");
	//printf("\nliste a avant rrr\n");
	//print_node_list(list_a);
	//printf("\nliste b avant rrr\n");
	//print_node_list(list_b);
	//rrr(&list_a, &list_b);
	//printf("\nliste a apres rrr\n");
	//print_node_list(list_a);
	//printf("\nliste b apres rrr\n");
	//print_node_list(list_b);

	//printf("\n----------------------------PB----------------------------");
	//printf("\nliste a avant pb\n");
	//print_node_list(list_a);
	//printf("\nliste b avant pb\n");
	//print_node_list(list_b);
	//pb(&list_a, &list_b);
	//pb(&list_a, &list_b);
	//pb(&list_a, &list_b);
	//printf("\nliste a apres pb\n");
	//print_node_list(list_a);
	//printf("\nliste b apres pb\n");
	//print_node_list(list_b);

	//printf("\n----------------------------PA----------------------------");
	//printf("\nliste a avant pa\n");
	//print_node_list(list_a);
	//printf("\nliste b avant pa\n");
	//print_node_list(list_b);
	//pa(&list_a, &list_b);
	//pa(&list_a, &list_b);
	//pa(&list_a, &list_b);
	//printf("\nliste a apres pa\n");
	//print_node_list(list_a);
	//printf("\nliste b apres pa\n");
	//print_node_list(list_b);

	//printf("\n----------------------------PB----------------------------");
	//printf("\nliste a avant pb\n");
	//print_node_list(list_a);
	//printf("\nliste b avant pb\n");
	//print_node_list(list_b);
	//pb(&list_a, &list_b);
	//printf("\nliste a apres pb\n");
	//print_node_list(list_a);
	//printf("\nliste b apres pb\n");
	//print_node_list(list_b);


	//printf("\nliste a avant rra\n");
	//print_node_list(list_a);
	//printf("\nliste a apres rra\n");
	//rra(&list_a);
	//print_node_list(list_a);

	//printf("\nliste b\n");
	//print_node_list(list_b);
	free(num);
	while (list_a)
	{
		t_list *tmp = list_a->next;;
		free(list_a);
		list_a = tmp;
	}


	while (list_b)
	{
		t_list *tmp = list_b->next;;
		free(list_b);
		list_b = tmp;
	}

	return (0);
}
