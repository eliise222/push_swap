/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:25:56 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/31 23:13:07 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	do_bench_action(char **args, int argc, t_bench *benchmark, int alg_type)
{
	if (argc <= 3)
		exit (0);
	if (alg_type == 1)
	{
		benchmark->simple = 1;
		do_simple(args, 3, argc, benchmark);
	}
	if (alg_type == 2)
	{
		benchmark->medium = 1;
		do_medium(args, 3, argc, benchmark);
	}
	if (alg_type == 3)
	{
		benchmark->complex = 1;
		do_complex(args, 3, argc, benchmark);
	}
	if (alg_type == 4)
	{
		benchmark->adaptive = 1;
		do_adaptive(args, 3, argc, benchmark);
	}
	display_bench(args, 3, argc, benchmark);
}

void	do_bench(char **args, int argc, t_bench *benchmark)
{
	if (verif_int(args[2]) && is_valid(args[2]))
	{
		benchmark->adaptive = 1;
		do_adaptive(args, 2, argc, benchmark);
		display_bench(args, 2, argc, benchmark);
	}
	else if (ft_strncmp(args[2], "--simple", ft_strlen("--simple")) == 0)
	{
		do_bench_action(args, argc, benchmark, 1);
	}
	else if (ft_strncmp(args[2], "--medium", ft_strlen("--medium")) == 0)
	{
		do_bench_action(args, argc, benchmark, 2);
	}
	else if (ft_strncmp(args[2], "--complex", ft_strlen("--complex")) == 0)
	{
		do_bench_action(args, argc, benchmark, 3);
	}
	else if (ft_strncmp(args[2], "--adaptive", ft_strlen("--adaptive")) == 0)
	{
		do_bench_action(args, argc, benchmark, 4);
	}
	else
		error();
}

void	do_algo_action(char **argv, int argc, t_bench *benchmark, int alg_type)
{
	if (argc <= 2)
		exit (0);
	if (alg_type == 1)
	{
		do_simple(argv, 2, argc, benchmark);
	}
	if (alg_type == 2)
	{
		do_medium(argv, 2, argc, benchmark);
	}
	if (alg_type == 3)
	{
		do_complex(argv, 2, argc, benchmark);
	}
	if (alg_type == 4)
	{
		do_adaptive(argv, 2, argc, benchmark);
	}
}

void	do_algo(char **argv, int argc, t_bench *benchmark)
{
	if (ft_strncmp(argv[1], "--bench", ft_strlen("--bench")) == 0)
	{
		if (argc <= 2)
			exit (0);
		benchmark->is_active = 1;
		do_bench(argv, argc, benchmark);
	}
	else if (ft_strncmp(argv[1], "--simple", ft_strlen("--simple")) == 0)
	{
		do_algo_action(argv, argc, benchmark, 1);
	}
	else if (ft_strncmp(argv[1], "--medium", ft_strlen("--medium")) == 0)
	{
		do_algo_action(argv, argc, benchmark, 2);
	}
	else if (ft_strncmp(argv[1], "--complex", ft_strlen("--complex")) == 0)
	{
		do_algo_action(argv, argc, benchmark, 3);
	}
	else if (!ft_strncmp(argv[1], "--adaptive", ft_strlen("--adaptive")))
	{
		do_algo_action(argv, argc, benchmark, 4);
	}
	else
		error();
}

int	main(int argc, char **argv)
{
	t_bench	*benchmark;

	if (argc <= 1)
		exit(0);
	benchmark = new_bench();
	if (verif_int(argv[1]) && is_valid(argv[1]))
	{
		do_adaptive(argv, 1, argc, benchmark);
	}
	else if (argv[1][0] == '-')
	{
		do_algo(argv, argc, benchmark);
	}
	else
		error();
	free(benchmark);
}
