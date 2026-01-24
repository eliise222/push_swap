/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:42:07 by srezzaq           #+#    #+#             */
/*   Updated: 2026/01/23 17:55:21 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_bench *benchmark)
{
	write(2, "Error\n", 6);
	free(benchmark);
	exit(1);
}

int	is_valid(const char	*s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

bool	ft_atoill(const char *s, long *res)
{
	long long	sign;
	int			i;

	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (sign == 1 && *res > (LONG_MAX - (s[i] - '0')) / 10)
			return (false);
		else if (sign == -1 && *res > (-(LONG_MIN + (s[i] - '0'))) / 10)
			return (false);
		*res = (*res * 10) + (s[i] - '0');
		i++;
	}
	return (true);
}

int	verif_int(const char	*s)
{
	long	val;

	val = 0;
	if (ft_atoill(s, &val) == false)
		return (0);
	return (1);
}

int	check_doubles(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
