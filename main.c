/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:56:08 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/08 17:04:44 by srezzaq          ###   ########.fr       */
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
	t_list	*list_a;
	t_list	*list_b;
	//int		*val_b;

	str = "45 78 9 -6 8";
	num = parsing(str);
	if(!num)
	{
		error();
		return(-1);
	}
	len = list_len(get_list(str));
	//int i = 0;
	//while(i < len)
	//{
	//	printf("%d -\n", num[i]);
	//	i++;
	//}
	list_a = get_node_list(num, len);

	printf("liste avant a simple algo\n");
	print_node_list(list_a);
	simplealg(list_a, list_b);
	printf("\nlist a apres simple algo\n");
	print_node_list(list_a);
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

	return (0);
}
