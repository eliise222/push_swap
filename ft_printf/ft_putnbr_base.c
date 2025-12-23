/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:45 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/22 16:57:25 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base, int fd)
{
	size_t	base_len;
	int		ret;

	ret = 0;
	base_len = ft_strlen_prf(base);
	if (n >= base_len)
	{
		ret += ft_putnbr_base(n / base_len, base, fd);
	}
	ret += ft_putchar_fd_prf(base[n % base_len], fd);
	return (ret);
}
