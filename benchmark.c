/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:14:12 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/19 18:07:42 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

t_bench	*new_bench()
{
	t_bench	*benchmark;

	benchmark = (t_bench *)malloc(sizeof(t_bench));
	benchmark->is_active = 0;
	benchmark->sa = 0;
	benchmark->sb = 0;
	benchmark->ss = 0;
	benchmark->pa = 0;
	benchmark->pb = 0;
	benchmark->ra = 0;
	benchmark->rb = 0;
	benchmark->rr = 0;
	benchmark->rra = 0;
	benchmark->rrb = 0;
	benchmark->rrr = 0;
	return(benchmark);
}

double	bench_disorder(int *copy_list, int size)
{
	long	mistakes;
	long	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	if (size < 2)
	{
		free(copy_list);
		return (0.0);
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (copy_list[i] > copy_list[j])
				mistakes++;
			j++;
		}
		i++;
	}
	free(copy_list);
	return ((double)mistakes / (double)total_pairs);
}

void	display_bench(char **args, int start, int len, t_bench *benchmark)
{
	int		tot_ops;
	int		*num_list;
	char	**copy_list;
	int		copy_list_len;
	double	dis;

	copy_list = copy_argv_offset(args, start, len);
	copy_list_len = list_len(copy_list);
	num_list = parsing(copy_list);
	dis = bench_disorder(num_list, copy_list_len);
	dis *= 100;
	tot_ops = benchmark->sa + benchmark->sb + benchmark->ss + benchmark->pa + benchmark->pb + benchmark->ra + benchmark->rb + benchmark->rr + benchmark->rra + benchmark->rrb + benchmark->rrr;
	printf("[bench] disorder: %lf%%\n", dis);
	printf("[bench] total_ops: %d\n", tot_ops);
	printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", benchmark->sa, benchmark->sb, benchmark->ss, benchmark->pa, benchmark->pb);
	printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", benchmark->ra, benchmark->rb, benchmark->rr, benchmark->rra, benchmark->rrb, benchmark->rrr);

}
