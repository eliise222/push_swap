/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:14:12 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/19 12:47:49 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

t_bench	new_bench()
{
	t_bench	benchmark;

	benchmark.is_active = 0;
	benchmark.sa = 0;
	benchmark.sb = 0;
	benchmark.ss = 0;
	benchmark.pa = 0;
	benchmark.pb = 0;
	benchmark.ra = 0;
	benchmark.rb = 0;
	benchmark.rr = 0;
	benchmark.rra = 0;
	benchmark.rrb = 0;
	benchmark.rrr = 0;
	return(benchmark);
}

//void	do_bench(t_bench benchmark)
//{
//	t_bench	benchmark;

//	benchmark = new_bench();
//}

//int main()
//{
//	do_bench();
//}
