/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:56:08 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/07 18:52:28 by srezzaq          ###   ########.fr       */
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

	list_b = ft_lstnew(NULL);

	printf("\nliste a avant ra\n");
	print_node_list(list_a);
	printf("\nliste a apres ra\n");
	ra(&list_a);
	print_node_list(list_a);

	printf("\nliste a avant sa\n");
	print_node_list(list_a);
	printf("\nliste a apres sa\n");
	sa(&list_a);
	print_node_list(list_a);

	printf("\nliste a avant rra\n");
	print_node_list(list_a);
	printf("\nliste a apres rra\n");
	rra(&list_a);
	print_node_list(list_a);

	printf("\nliste b\n");
	print_node_list(list_b);
	free(num);

	return (0);
}
