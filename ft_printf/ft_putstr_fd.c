/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:52:37 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/22 16:57:49 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_prf(char *s, int fd)
{
	int	ret;

	if (!s)
		return (write(fd, "(null)", 6));
	ret = ft_strlen_prf(s);
	write(fd, s, ft_strlen_prf(s));
	return (ret);
}

// int main()
// {
//     char a[] = "abc";
//     ft_putstr_fd(a, 1);
// }
