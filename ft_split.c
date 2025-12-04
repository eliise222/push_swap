/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:14:08 by elise             #+#    #+#             */
/*   Updated: 2025/08/28 16:40:04 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	int	i;
	int	nbm;

	i = 0;
	nbm = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nbm += 1;
		i++;
	}
	return (nbm);
}

int	get_next_word(const char *s, char c, int start, char **word)
{
	int	i;
	int	len;

	while (s[start] && s[start] == c)
		start ++;
	i = start;
	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	*word = ft_substr(s, start, len);
	if (*word == NULL)
		return (-1);
	return (i);
}

void	free_tab(char **tab, int word_index)
{
	while (word_index > 0)
	{
		word_index--;
		free(tab[word_index]);
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		nbm;
	char	**tab;
	int		pos;
	int		word_index;

	if (s == NULL)
		return (NULL);
	nbm = count_words(s, c);
	tab = malloc(sizeof(char *) * (nbm + 1));
	if (tab == NULL )
		return (NULL);
	pos = 0;
	word_index = 0;
	while (word_index < nbm)
	{
		pos = get_next_word(s, c, pos, &tab[word_index]);
		if (pos == -1)
		{
			free_tab(tab, word_index);
			return (NULL);
		}
		word_index++;
	}
	tab[word_index] = NULL;
	return (tab);
}
