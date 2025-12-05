/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:56:08 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/05 15:59:06 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/srcs/ft_printf.h"
#include <stdio.h>

int	main()
{
	char		*str;
	long long	*num;
	int			len;
	t_list		*num_list;

	*str = "45 78 9 -6 8";
	*num = parsing(str);
	if(!num)
	{
		error();
		return(-1);
	}
	len = list_len(get_list(str));
	//int i = 0;
	//while(i < len)
	//{
	//	printf("%lld -\n", num[i]);
	//	i++;
	//}
	num_list = get_node_list(num, len);
	print_node_list(num_list);
	free(num);

	return (0);
}
