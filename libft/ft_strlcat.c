/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:12:54 by elise             #+#    #+#             */
/*   Updated: 2025/08/31 01:00:39 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;

	i = ft_strlen(dest);
	j = 0;
	len_dest = i;
	if (i >= size)
		return (size + ft_strlen(src));
	else
	{
		while (src[j] && i < (size - 1))
			dest[i++] = src[j++];
		dest[i] = '\0';
		return (len_dest + ft_strlen(src));
	}
}
