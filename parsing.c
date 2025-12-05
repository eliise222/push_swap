/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:10:43 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/05 15:43:17 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

char	**get_list(char	*str)
{
	char	**resul;
	char	sep;

	sep = ' ';
	resul = ft_split(str, sep);
	return (resul);
}

void	free_list(char **enter)
{
	int	j;

	j = 0;
	while (enter[j])
	{
		free(enter[j]);
		j++;
	}
	free(enter);
}

int	is_valid_enter(char **enter)
{
	int	j;

	j = 0;
	while (enter[j])
	{
		if (is_valid (enter[j]) == 0)
		{
			free_list (enter);
			return (0);
		}
		j++;
	}
	return (1);
}

long long	*num_list(char **char_list)
{
	long long	*list;
	int			i;
	int			len;

	len = list_len(char_list);
	i = 0;
	list = (long long *)malloc(sizeof(long long) * (len));
	if (!list)
		return (NULL);
	while (i < len)
	{
		list[i] = ft_atoill(char_list[i]);
		i++;
	}
	free_list(char_list);
	return (list);
}

long long	*parsing(char *str)
{
	char		**get_str;
	long long	*get_num;
	int			len;

	get_str = get_list(str);
	len = list_len(get_str);
	if (!is_valid_enter(get_str))
	{
		return (NULL);
	}
	get_num = num_list(get_str);
	return (get_num);
}
