/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium_alg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:26:18 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/18 19:01:37 by srezzaq          ###   ########.fr       */
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

int	max_val(t_list	**b)
{
	int		i;
	int		pos;
	int		val;
	t_list	*tmp;

	if (!b || !*b)
		return (-1);
	tmp = *b;
	i = 0;
	pos = 0;
	val = tmp->content;
	while (tmp != NULL)
	{
		if (val < tmp->content)
		{
			val = tmp->content;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}
