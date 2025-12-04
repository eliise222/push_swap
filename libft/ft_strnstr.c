/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:13:17 by elise             #+#    #+#             */
/*   Updated: 2025/08/28 16:59:39 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < size && s1[i])
	{
		if (s1[i] != s2[j])
			i++;
		else
		{
			while (s1[i + j] == s2[j] && s2[j] && (i + j) < size)
			{
				j++;
			}
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
			j = 0;
			i++;
		}
	}
	return (NULL);
}
