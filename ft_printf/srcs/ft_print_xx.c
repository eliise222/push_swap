/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:07:01 by elise             #+#    #+#             */
/*   Updated: 2025/09/06 01:20:20 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xx(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_base(n, 1, "0123456789ABCDEF");
	return (ft_nbrlen(n, 16));
}
