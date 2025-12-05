/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:42:07 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/05 15:42:08 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
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

	is_valid(s);
	val = ft_atoill(s);
	if (val < INT_MIN || val > INT_MAX)
		error();
	val = (int)val;
	return (val);
}

int	list_len(char **resul)
{
	int	i;

	if (!resul)
		return (0);
	i = 0;
	while (resul[i])
	{
		i++;
	}
	return (i);
}
