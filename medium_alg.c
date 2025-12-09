/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:48:43 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/09 19:43:11 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

int	ft_sqrt(int nb)
{
	int n;

	if (nb <= 0)
		return (0);
	n = 1;
	while (n <= nb / n)
		n++;
	return (n - 1);
}
//int	chunk(t_list	*a)
//{
//	int	i;

//	i = ft_lstsize(a);
//	i = ft_sqrt(i);
//	return(i);

//}
int ft_ceil(int nb1, int nb2)
{
	int ret;

	ret = nb1/nb2;
	if(nb1%nb2 != 0)
	{
		ret ++;
		return(ret);
	}
	return (ret);
}

int **virtual_list(t_list	*a)
{
	int soretd_list[ft_lstsize(a)];
	t_list *tmp;
	int i;
	int chunk_size;
	int **all_chunks;
	int size;

	size = ft_lstsize(a);
	chunk_size = ft_sqrt(size);
	i = 0;
	tmp = a;
	while(tmp != NULL)
	{
		soretd_list[i] = *(int*)tmp->content;
		i++;
		tmp = tmp->next;
	}
	insertion_sort(soretd_list, size);


	int i2 = 0;
	while(i2<i)
	{
		//printf("\nsorted n = %d\n", soretd_list[i2]);
		i2++;
	}
	//int s = 12 / 3;
	//printf("\n%d\n", s);

	all_chunks = malloc(sizeof(int *) * (ft_ceil(size, chunk_size)));
	int j = 0;
	int y = 0;
	while(j<(size/chunk_size))
	{
		int *chunk_part = malloc(sizeof(int) * (chunk_size));
		int z = 0;
		while(z<chunk_size)
		{
			chunk_part[z] = soretd_list[y];
			y++;
			z++;
		}
		all_chunks[j] = chunk_part;
		j++;
	}
	if(size%chunk_size != 0)
	{
		int t = size%chunk_size;
		int o = 0;
		int *chunk_part = malloc(sizeof(int) * (t));
		while(o<t)
		{
			chunk_part[o] = soretd_list[y];
			y++;
			o++;
		}
		all_chunks[j] = chunk_part;
	}
	return(all_chunks);
}
void medium_alg(t_list	**a, t_list	**b)
{
	int **list;



}
