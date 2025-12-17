/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_medium_alg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:45:54 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/11 19:19:36 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int reverse_search_chunk_element(t_list	**a, int *chunk, int size)
{
	int *copy_list;
	int copylist_size;
	t_list *tmp;
	int i = 0;
	int j;
	int ret = 0;
	
	tmp = *a;
	copylist_size = ft_lstsize(*a);
	copy_list = malloc(sizeof(int) * (copylist_size));
	j = copylist_size -1;
	while(tmp != NULL)
	{
		copy_list[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	while(j>=0)
	{
		if(is_in(copy_list[j], chunk, size))
		{
			break;
		}
		ret++;
		j--;
	}
	free(copy_list);
	return(ret);
}

int	search_chunk_element(t_list	**a, int *chunk, int size)
{
	t_list *tmp1;
	int i1;

	i1 = 0;
	tmp1 = *a;
	while(tmp1 != NULL)
	{
		if(is_in(tmp1->content, chunk, size))
		{
			break;
		}
		i1++;
		tmp1 = tmp1->next;
	}
	return(i1);
}

void put_chunk_in_b(int *list, int chunk_size, t_list	**a, t_list	**b)
{
	int i;
	int c;
	int	up_chunk;
	int down_chunk;

	i = 0;
	c = 0;
	while(i<chunk_size)
	{
		up_chunk = search_chunk_element(a, &list[0], chunk_size);
		down_chunk = reverse_search_chunk_element(a, &list[0], chunk_size);
		if(up_chunk < down_chunk)
		{
			c = 0;
			while(c < up_chunk)
			{
				ra(a);
				c++;
			}
		}
		else
		{
			c = 0;
			while(c <= down_chunk)
			{
				rra(a);
				c++;
			}
		}
		pb(a, b);
		i++;
	}
}

int	max_val(t_list	**b)
{
	int		i;
	int		pos;
	int		val;
	t_list	*tmp;

	if (!b || !*b)
		return (-1);
	tmp = *b;
	i = 0;
	pos = 0;
	val = tmp->content;
	while (tmp != NULL)
	{
		if (val < tmp->content)
		{
			val = tmp->content;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}
void put_in_a(t_list	**a, t_list	**b)
{
	int	size;
	int	i;

	while (*b)
	{
		i = max_val(b);
		size = ft_lstsize(*b);
		if (i <= size / 2)
		{
			while ( i > 0 )
			{
				rb(b);
				i--;
			}
		}
		else
		{
			while (i < size)
			{
				rrb(b);
				i++;
			}
		}
		pa(a, b);
	}
}