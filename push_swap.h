/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:09:18 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/17 18:06:48 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);

int			is_valid(const char	*s);
void		error(void);
long long	ft_atoill(const char	*s);
int			verif_int(const char	*s);
char		**copy_argv_offset(char **args, int start, int len);
int			list_len(char **resul);
int			*parsing(char **str);

t_list		*get_node_list(int *num, int len);
t_list		*get_list_a(char **args, int start, int len);
void		free_linked_list(t_list *list);
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

void		pa(t_list	**a, t_list	**b);
void		pb(t_list	**a, t_list	**b);

void		simplealg(t_list	**a, t_list	**b);
int			min_val(t_list	**a);

int			get_sup_num(t_list **a, t_list *node);
void		assign_index(t_list **a);
int			count_nb(int a);

void		medium_alg(t_list	**a, t_list	**b);
void		sort(int *a, int size);
int			is_in(int val, int *list, int size);
int			ft_ceil(int nb1, int nb2);
int			ft_sqrt(int nb);
int			**virtual_list(t_list *a);
void		put_chunk_in_b(int *list, int chunk_size, t_list **a, t_list **b);
void		put_in_a(t_list	**a, t_list	**b);

void		do_adaptive( char **args, int start, int len);
void		do_simple( char **args, int start, int len);
void		do_medium( char **args, int start, int len);
void		do_complex( char **args, int start, int len);

#endif
