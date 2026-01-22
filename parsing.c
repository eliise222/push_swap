/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:10:43 by srezzaq           #+#    #+#             */
/*   Updated: 2026/01/21 17:00:21 by srezzaq          ###   ########.fr       */
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
// char	*forcopyargv(char **args, int start, char *tmp, char *join)
// {
// 	join = ft_strdup("");
// 	tmp = join;
// 	if (join[0] != '\0')
// 	{
// 		tmp = join;
// 		join = ft_strjoin(tmp, " ");
// 		free(tmp);
// 	}
// 	if (!join)
// 		return (NULL);
// 	tmp = join;
// 	join = ft_strjoin(tmp, args[start]);
// 	free(tmp);
// 	if (!join)
// 		return (NULL);
// 	return (join);
// }

char	**copy_argv_offset(char **args, int start, int len)
{
	char	**ret;
	char	*join;
	char	*tmp;

	if (start >= len)
		return (NULL);
	join = ft_strdup("");
	if (!join)
		return (NULL);
	tmp = NULL;
	while (start < len)
	{
		tmp = join;
		join = ft_strjoin(tmp, args[start++]);
		free(tmp);
		if (!join)
			return (NULL);
		if (args[start])
			join = ft_add_space(join);
	}
	ret = ft_split(join, ' ');
	free(join);
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

int	*parsing(char **str, t_bench *benchmark)
{
	int		*get_num;
	int		len;
	int		i;

	i = 0;
	if (!is_valid_enter(str))
	{
		while (str[i])
			free(str[i++]);
		free(str);
		error(benchmark);
		return (NULL);
	}
	len = list_len(str);
	get_num = num_list(str);
	if (check_doubles(get_num, len))
	{
		free(get_num);
		error(benchmark);
		return (NULL);
	}
	return (get_num);
}
