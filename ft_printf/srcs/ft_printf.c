/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:12:26 by elise             #+#    #+#             */
/*   Updated: 2025/09/05 17:30:46 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_if(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (format[1] == 'c')
		count += ft_print_c(args);
	else if (format[1] == 's')
		count += ft_print_s(args);
	else if (format[1] == 'd' || format[1] == 'i')
		count += ft_print_i_or_d(args);
	else if (format[1] == 'p')
		count += ft_print_p(args);
	else if (format [1] == 'u')
		count += ft_print_u(args);
	else if (format[1] == 'x')
		count += ft_print_x(args);
	else if (format[1] == 'X')
		count += ft_print_xx(args);
	else if (format[1] == '%')
		count += ft_print_percent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_printf_if(&format[i], args);
			i += 2;
		}
		else
		{
			write(1, &format[i++], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
