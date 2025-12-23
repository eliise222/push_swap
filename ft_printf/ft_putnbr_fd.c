/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:52:12 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/22 16:52:04 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_prf(int n, int fd)
{
	long int	n1;
	int			ret;

	n1 = n;
	ret = 0;
	if (n < 0)
	{
		ret += ft_putchar_fd_prf('-', fd);
		n1 = -n1;
	}
	if (n1 <= 9)
		ret += ft_putchar_fd_prf(n1 + '0', fd);
	else
	{
		ret += ft_putnbr_fd_prf(n1 / 10, fd);
		ret += ft_putnbr_fd_prf(n1 % 10, fd);
	}
	return (ret);
}

// int main()
// {
//     ft_putnbr_fd(2147483647, 1);
// }
