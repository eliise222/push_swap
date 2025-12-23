/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:51:01 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/22 16:57:16 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(int fd, char const *str, ...);
int		ft_putchar_fd_prf(char c, int fd);
size_t	ft_strlen_prf(const	char *s);
int		ft_putstr_fd_prf(char *s, int fd);
int		ft_putnbr_fd_prf(int n, int fd);
int		ft_putunsnbr_fd(unsigned int n, int fd);
int		ft_putnbr_base(unsigned long n, char *base, int fd);
int		ft_putptr(void *ptr, int fd);

#endif
