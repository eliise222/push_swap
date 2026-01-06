/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:50:17 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/22 16:54:52 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x(unsigned int a, int fd)
{
	return (ft_putnbr_base(a, "0123456789abcdef", fd));
}

int	ft_put_x_maj(unsigned int a, int fd)
{
	return (ft_putnbr_base(a, "0123456789ABCDEF", fd));
}

int	convers(va_list *list, char *str, int fd)
{
	if (*str == 'c')
		return (ft_putchar_fd_prf(va_arg(*list, int), fd));
	else if (*str == 's')
		return (ft_putstr_fd_prf(va_arg(*list, char *), fd));
	else if (*str == 'p')
		return (ft_putptr(va_arg(*list, char *), fd));
	else if (*str == 'i' || *str == 'd')
		return (ft_putnbr_fd_prf(va_arg(*list, int), fd));
	else if (*str == 'u')
		return (ft_putunsnbr_fd(va_arg(*list, unsigned int), fd));
	else if (*str == 'x')
		return (ft_put_x(va_arg(*list, unsigned int), fd));
	else if (*str == 'X')
		return (ft_put_x_maj(va_arg(*list, unsigned int), fd));
	else if (*str == '%')
		return (ft_putchar_fd_prf('%', fd));
	return (0);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	list;
	int		ret;

	if (!str)
		return (0);
	ret = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
			{
				ret += convers(&list, (char *)str, fd);
			}
		}
		else
		{
			ret += ft_putchar_fd_prf(*str, fd);
		}
		str++;
	}
	va_end (list);
	return (ret);
}
