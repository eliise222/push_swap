/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:32:25 by srezzaq           #+#    #+#             */
/*   Updated: 2026/01/02 18:18:18 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

static void	exec_instr(char *line, t_list **a, t_list **b, t_bench *benchmark)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, benchmark);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, benchmark);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, benchmark);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, benchmark);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b, benchmark);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a, benchmark);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, benchmark);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, benchmark);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, benchmark);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, benchmark);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, benchmark);
	else
		error();
}

static void	read_and_execute(t_list **a, t_list **b, t_bench *benchmark)
{
	char	*line;

	while ((line = get_next_line(0)))
	{
		exec_instr(line, a, b, benchmark);
		free(line);
	}
}

int	is_sorted(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list;
	tmp2 = (*list)->next;
	while (tmp2)
	{
		if (tmp->content > tmp2->content)
			return (0);
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_bench	*benchmark;

	if (argc == 1)
		exit (0);
	benchmark = new_bench();
	benchmark->is_checker = 1;
	a = get_list_a(argv, 1, argc);
	b = NULL;
	if (!a && argc > 1)
		error();
	read_and_execute(&a, &b, benchmark);
	if (is_sorted(&a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(benchmark);
	free_linked_list(a);
	free_linked_list(b);
	return (0);
}
