/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:13:13 by elise             #+#    #+#             */
/*   Updated: 2025/08/28 16:40:50 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *S1, const char *S2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && S1[i] != '\0' && S2[i] != '\0')
	{
		if (S1[i] != S2[i])
			return ((unsigned char)S1[i] - (unsigned char)S2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)S1[i] - (unsigned char)S2[i]);
	return (0);
}
