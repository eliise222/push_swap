/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:17:54 by elise             #+#    #+#             */
/*   Updated: 2025/09/06 01:25:06 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_print_c(va_list args);
int		ft_print_i_or_d(va_list args);
int		ft_print_xx(va_list args);
int		ft_print_x(va_list args);
int		ft_print_u(va_list args);
int		ft_print_s(va_list args);
int		ft_print_percent(void);
int		ft_print_p(va_list args);
int		ft_nbrlen(unsigned int n, int base_len);
void	ft_putnbr_base(unsigned int n, int fd, char *base);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_base_long(unsigned long n, int fd, char *base);
int		ft_nbrlen_long(unsigned long n, int base_len);
void	ft_putstr_fd(char *s, int fd);

#endif
