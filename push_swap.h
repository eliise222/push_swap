/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:09:18 by srezzaq           #+#    #+#             */
/*   Updated: 2026/01/01 23:38:50 by elise            ###   ########.fr       */
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

typedef struct s_bench
{
	int	is_active;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
}					t_bench;

t_bench		*new_bench(void);
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);

int			is_valid(const char	*s);
void		error(void);
long long	ft_atoill(const char	*s);
int			verif_int(const char	*s);
int			check_doubles(int *tab, int size);
char		**copy_argv_offset(char **args, int start, int len);
int			list_len(char **resul);
int			*parsing(char **str);

t_list		*get_node_list(int *num, int len);
t_list		*get_list_a(char **args, int start, int len);
void		free_linked_list(t_list *list);
void		print_node_list(t_list *head);

void		ra(t_list	**a, t_bench *benchmark);
void		rb(t_list	**b, t_bench *benchmark);
void		rr(t_list	**a, t_list	**b, t_bench *benchmark);

void		sa(t_list	**stack_a, t_bench *benchmark);
void		sb(t_list	**stack_b, t_bench *benchmark);
void		ss(t_list	**stack_a, t_list	**stack_b, t_bench *benchmark);
t_list		*reversenode(t_list	*a);

void		rra(t_list	**a, t_bench *benchmark);
void		rrb(t_list	**b, t_bench *benchmark);
void		rrr(t_list	**a, t_list	**b, t_bench *benchmark);
void		reverse_all(t_list	**a);

void		pa(t_list	**a, t_list	**b, t_bench *benchmark);
void		pb(t_list	**a, t_list	**b, t_bench *benchmark);

void		simplealg(t_list	**a, t_list	**b, t_bench *benchmark);
void		put_min_in_b(t_list **a, t_list **b, t_bench *benchmark);
int			display_instr(void);
int			min_val(t_list	**a);

int			get_sup_num(t_list **a, t_list *node);
void		assign_index(t_list **a);
int			count_nb(int a);
void		radix_sort(t_list **a, t_list **b, t_bench *benchmark);

void		medium_alg(t_list	**a, t_list	**b, t_bench *benchmark);
void		sort(int *a, int size);
int			is_in(int val, int *list, int size);
int			ft_ceil(int nb1, int nb2);
int			ft_sqrt(int nb);
int			max_val(t_list	**b);
int			**virtual_list(t_list *a);
int			reverse_search_chunk_element(t_list **a, int *chunk, int size);
int			search_chunk_element(t_list **a, int *chunk, int size);
void		repeat_ra(int chunk, t_list **a, t_bench *benchmark);
void		repeat_rra(int chunk, t_list	**a, t_bench *benchmark);
void		put_chunk_in_b(int *list, int chunk_size, t_list **a, t_list **b, t_bench *be);
void		put_in_a(t_list	**a, t_list	**b, t_bench *benchmark);

void		do_adaptive( char **args, int start, int len, t_bench *benchmark);
void		do_simple( char **args, int start, int len, t_bench *benchmark);
void		do_medium( char **args, int start, int len, t_bench *benchmark);
void		do_complex( char **args, int start, int len, t_bench *benchmark);

double		disorder(t_list **list_a, int size, int *copy_list);
int			*list_copy(t_list **list);
void		display_bench(char **args, int start, int len, t_bench *benchmark);
void		display_disorder_only(double dis);

void		tiny_alg_3(t_list **list, t_bench *benchmark);
void		tiny_alg_2(t_list **list, t_bench *benchmark);
void		tiny_sort(t_list **list_a, t_list **list_b, t_bench *benchmark);

void		chunksort(t_list **a, t_list **b, t_bench *benchmark);

#endif
