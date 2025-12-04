/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:12:44 by elise             #+#    #+#             */
/*   Updated: 2025/08/28 16:39:37 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*des;
	const unsigned char	*sr;
	size_t				i;

	des = (unsigned char *) dest;
	sr = (const unsigned char *) src;
	i = n;
	if (des > sr)
	{
		while (i > 0)
		{
			i--;
			des[i] = sr[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			des[i] = sr[i];
			i++;
		}
	}
	return (dest);
}
