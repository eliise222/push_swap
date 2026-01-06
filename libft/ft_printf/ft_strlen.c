/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:52:53 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/22 16:57:59 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_prf(const	char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// #include <stdio.h>

// int main()
// {
//     char test[] = "abcdef";
//     size_t taille = ft_strlen(test);
//     int tailleInt = (int)taille;
//     printf("%zu", taille);
//     printf("\n");
//     printf("%d", tailleInt);
// }
