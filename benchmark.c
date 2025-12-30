/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:14:12 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/30 13:57:32 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

t_bench	*new_bench(void)
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
	benchmark->simple = 0;
	benchmark->medium = 0;
	benchmark->complex = 0;
	benchmark->adaptive = 0;
	return (benchmark);
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
		return (0.0);
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
	return ((double)mistakes / (double)total_pairs);
}

void	display_moves(t_bench *benchmark, double dis, int tot_ops)
{
	int	disorder;
	int	int_part;
	int	fract_part;

	disorder = dis * 10000;
	int_part = disorder / 100;
	fract_part = disorder % 100;
	ft_printf(2, "[bench] disorder: %d.%d%%\n", int_part, fract_part);
	tot_ops += benchmark->sa + benchmark->sb + benchmark->ss;
	tot_ops += benchmark->pa + benchmark->pb + benchmark->ra;
	tot_ops += benchmark->rb + benchmark->rr + benchmark->rra;
	tot_ops += benchmark->rrb + benchmark->rrr;
	ft_printf(2, "[bench] total_ops: %d\n", tot_ops);
	ft_printf(2, "[bench] sa: %d ", benchmark->sa);
	ft_printf(2, "sb: %d ", benchmark->sb);
	ft_printf(2, "ss: %d ", benchmark->ss);
	ft_printf(2, "pa: %d ", benchmark->pa);
	ft_printf(2, "pb: %d\n", benchmark->pb);
	ft_printf(2, "[bench] ra: %d ", benchmark->ra);
	ft_printf(2, "rb: %d ", benchmark->rb);
	ft_printf(2, "rr: %d ", benchmark->rr);
	ft_printf(2, "rra: %d ", benchmark->rra);
	ft_printf(2, "rrb: %d ", benchmark->rrb);
	ft_printf(2, "rrr: %d\n", benchmark->rrr);
}

void	display_adap_strg(double dis)
{
	ft_printf(2, "[bench] strategy: Adaptive ");
	if (dis == 0.0)
		ft_printf(2, "\n");
	else if (dis < 0.2)
		ft_printf(2, "/ O(n2)\n");
	else if (0.2 <= dis && dis < 0.5)
		ft_printf(2, "/ O(n n))\n");
	else if (dis >= 0.5)
		ft_printf(2, "/ O((n log n)\n");
}

void	display_bench(char **args, int start, int len, t_bench *benchmark)
{
	int		tot_ops;
	int		*num_list;
	char	**copy_list;
	int		copy_list_len;
	double	dis;

	tot_ops = 0;
	copy_list = copy_argv_offset(args, start, len);
	copy_list_len = list_len(copy_list);
	num_list = parsing(copy_list);
	dis = bench_disorder(num_list, copy_list_len);
	free(num_list);
	if (benchmark->adaptive)
		display_adap_strg(dis);
	else if (benchmark->simple)
		ft_printf(2, "[bench] strategy: Simple / O(n2)\n");
	else if (benchmark->medium)
		ft_printf(2, "[bench] strategy: Medium / O(n n)\n");
	else if (benchmark->complex)
		ft_printf(2, "[bench] strategy: Complex / O(n log n)\n");
	display_moves(benchmark, dis, tot_ops);
}
