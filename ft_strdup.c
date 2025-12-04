/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:08:04 by elise             #+#    #+#             */
/*   Updated: 2025/12/04 15:04:49 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*d;
	size_t		i;

	size = ft_strlen(s) + 1;
	d = malloc(size);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
