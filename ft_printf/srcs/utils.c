/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:43:51 by elise             #+#    #+#             */
/*   Updated: 2025/09/06 01:24:44 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int n, int fd, char *base)
{
	char			c;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_putnbr_base(n / base_len, fd, base);
	c = base[n % base_len];
	ft_putchar_fd(c, fd);
}

int	ft_nbrlen(unsigned int n, int base_len)
{
	int	len;

	len = 1;
	while (n >= (unsigned int)base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

/*void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putstr_fd("-", fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	ft_putchar_fd(c, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}
