/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:36:50 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/17 12:41:11 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/srcs/ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if(argc <= 1)
	{
        exit(0);
    }

    if(verif_int(argv[1]) && is_valid(argv[1]))
    {
        int *numList;
        char **copyList;
        int len;
        t_list *list_a;
        t_list *list_b;

        list_a = NULL;
        list_b = NULL;
        copyList = copy_argv_offset(argv, 1, argc);
        len = list_len(copyList);
        numList = parsing(copyList);
        // if(!numList)
        //     write(2, "Error\n", 6);
        list_a = get_node_list(numList, len);
        //print_node_list(list_a);
        simplealg(&list_a, &list_b);

        while (list_a)
        {
            t_list *tmp = list_a->next;
            free(list_a);
            list_a = tmp;
        }


        while (list_b)
        {
            t_list *tmp = list_b->next;
            free(list_b);
            list_b = tmp;
        }
    }
    else if(argv[1][0] == '-')
    {
        if(ft_strncmp(argv[1], "--bench", ft_strlen("--bench")) == 0)
        {
            ft_putstr_fd("bench", 2);
        }
        else if(ft_strncmp(argv[1], "--simple", ft_strlen("--simple")) == 0)
        {
            ft_putstr_fd("simple", 1);
        }
         else if(ft_strncmp(argv[1], "--medium", ft_strlen("--medium")) == 0)
        {
            ft_putstr_fd("medium", 1);
        }
         else if(ft_strncmp(argv[1], "--complex", ft_strlen("--complex")) == 0)
        {
            ft_putstr_fd("complex", 1);
        }
        else
        {
            error();
        }
    }
    else
    {
        error();
    }
}
