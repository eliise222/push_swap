/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:36:50 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/17 17:29:01 by srezzaq          ###   ########.fr       */
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
		do_adaptive(argv, 1, argc);
    }
    else if(argv[1][0] == '-')
    {
        if(ft_strncmp(argv[1], "--bench", ft_strlen("--bench")) == 0)
        {
            ft_putstr_fd("bench", 2);
        }
        else if(ft_strncmp(argv[1], "--simple", ft_strlen("--simple")) == 0)
        {
            //ft_putstr_fd("simple", 1);
			do_simple(argv, 2, argc);
        }
         else if(ft_strncmp(argv[1], "--medium", ft_strlen("--medium")) == 0)
        {
            //ft_putstr_fd("medium", 1);
			do_medium(argv, 2, argc);
        }
         else if(ft_strncmp(argv[1], "--complex", ft_strlen("--complex")) == 0)
        {
            //ft_putstr_fd("complex", 1);
			do_complex(argv, 2, argc);
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
