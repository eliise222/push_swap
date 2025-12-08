/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:09:18 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/08 17:03:12 by srezzaq          ###   ########.fr       */
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
int			*parsing(char *str);
t_list		*get_node_list(int *num, int len);
void		print_node_list(t_list *head);

void		ra(t_list	**a);
void		rb(t_list	**b);
void		rr(t_list	**a, t_list	**b);

void		sa(t_list	**stack_a);
void		sb(t_list	**stack_b);
void		ss(t_list	**stack_a, t_list	**stack_b);
t_list		*reversenode(t_list	*a);

void		rra(t_list	**a);
void		rrb(t_list	**b);
void		rrr(t_list	**a, t_list	**b);
void		reverse_all(t_list	**a);

void	pa(t_list	**a, t_list	**b);
void	pb(t_list	**a, t_list	**b);

#endif
