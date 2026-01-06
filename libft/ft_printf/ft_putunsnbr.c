/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:52:43 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/22 16:56:08 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnbr_fd(unsigned int n, int fd)
{
	int	ret;

	ret = 0;
	if (n <= 9)
		ret += ft_putchar_fd_prf(n + '0', fd);
	else
	{
		ret += ft_putunsnbr_fd(n / 10, fd);
		ret += ft_putunsnbr_fd(n % 10, fd);
	}
	return (ret);
}
