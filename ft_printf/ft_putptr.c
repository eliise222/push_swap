/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:52:22 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/22 16:55:51 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr, int fd)
{
	unsigned long	ad;
	int				ret;

	ret = 0;
	if (!ptr)
	{
		ret += ft_putstr_fd_prf("(nil)", fd);
		return (ret);
	}
	ad = (unsigned long)ptr;
	ret += ft_putstr_fd_prf("0x", fd);
	ret += ft_putnbr_base(ad, "0123456789abcdef", fd);
	return (ret);
}
