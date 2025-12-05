/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:09:18 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/05 15:42:35 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

int			is_valid(const char	*s);
void		error(void);
long long	ft_atoill(const char	*s);
char		**get_list(char	*str);
int			list_len(char **resul);
long long	*parsing(char *str);
t_list		*get_node_list(long long *num, int len);
void		print_node_list(t_list *head);

#endif
