/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:10:43 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/23 18:39:23 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

char	**copy_argv_offset(char **args, int start, int len)
{
	char	**ret;
	int		i;

	if (start >= len)
		return (NULL);
	ret = malloc(sizeof(char *) * ((len - start) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (start < len)
	{
		ret[i] = ft_strdup(args[start]);
		i++;
		start ++;
	}
	ret[i] = NULL;
	return (ret);
}

int	is_valid_enter(char **enter)
{
	int	j;

	j = 0;
	while (enter[j])
	{
		if (!is_valid (enter[j]) || !verif_int(enter[j]))
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	*num_list(char **char_list)
{
	int	*list;
	int	i;
	int	len;

	len = list_len(char_list);
	i = 0;
	list = (int *)malloc(sizeof(int) * (len));
	if (!list)
		return (NULL);
	while (i < len)
	{
		list[i] = ft_atoi(char_list[i]);
		i++;
	}
	free_list(char_list);
	return (list);
}

int	*parsing(char **str)
{
	int		*get_num;
	int		len;

	if (!is_valid_enter(str))
	{
		error();
		return (NULL);
	}
	len = list_len(str);
	get_num = num_list(str);
	if (check_doubles(get_num, len))
	{
		free(get_num);
		error();
		return (NULL);
	}
	return (get_num);
}
