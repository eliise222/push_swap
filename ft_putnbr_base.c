/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:45 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/07 14:33:55 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	size_t	base_len;
	int		ret;

	ret = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ret += ft_putnbr_base(n / base_len, base);
	}
	ret += ft_putchar_fd(base[n % base_len], 1);
	return (ret);
}
