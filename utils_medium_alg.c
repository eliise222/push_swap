/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium_alg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:26:18 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/11 17:48:37 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_sqrt(int nb)
{
	int	n;

	if (nb <= 0)
		return (0);
	n = 1;
	while (n <= nb / n)
		n++;
	return (n - 1);
}

int	ft_ceil(int nb1, int nb2)
{
	int	ret;

	ret = nb1 / nb2;
	if (nb1 % nb2 != 0)
	{
		ret ++;
		return (ret);
	}
	return (ret);
}

void	sort(int *a, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	j = 0;
	while (i < size)
	{
		j = i;
		tmp = a[i];
		while (j > 0 && a[j - 1] > tmp)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;
		i++;
	}
}

int	is_in(int val, int *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (list[i] == val)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
