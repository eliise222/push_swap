/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:11:34 by elise             #+#    #+#             */
/*   Updated: 2025/09/06 01:39:55 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_long(unsigned long n, int fd, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n >= (unsigned long)base_len)
		ft_putnbr_base_long(n / base_len, fd, base);
	ft_putchar_fd(base[n % base_len], fd);
}

int	ft_nbrlen_long(unsigned long n, int base_len)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

int	ft_print_p(va_list args)
{
	void			*ptr;
	unsigned long	a;
	int				len;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	a = (unsigned long) ptr;
	write(1, "0x", 2);
	ft_putnbr_base_long(a, 1, "0123456789abcdef");
	len = 2 + ft_nbrlen_long(a, 16);
	return (len);
}
/*#include <stdio.h>
int main(void)
{
	ft_printf("Pointeur NULL : %p\n", NULL);
	printf("Pointeur NULL : %p\n\n", NULL);
}*/
