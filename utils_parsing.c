/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:42:07 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/23 12:54:25 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
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
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atoill(const char	*s)
{
	long long	sign;
	long long	res;
	int			i;

	sign = 1;
	res = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

int	verif_int(const char	*s)
{
	long long	val;

	val = ft_atoill(s);
	if (val < INT_MIN || val > INT_MAX)
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

// int	verif_int(const char	*s)
// {
// 	long long	val;

// 	is_valid(s);
// 	val = ft_atoill(s);
// 	if (val < INT_MIN || val > INT_MAX)
// 		error();
// 	val = (int)val;
// 	return (val);
// }
