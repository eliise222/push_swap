/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:49:04 by srezzaq           #+#    #+#             */
/*   Updated: 2025/12/16 20:18:46 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int *list_copy(t_list **list)
{
    int *copy_list;
    int copylist_size;
    t_list *tmp;
    int     i;

    tmp = *list;
	copylist_size = ft_lstsize(*list);
    i = 0;
	copy_list = malloc(sizeof(int) * (copylist_size));
    if(!copy_list)
        return (NULL);
	while(tmp != NULL)
	{
		copy_list[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
    return (copy_list);
}

double disorder(t_list **list_a, int size)
{
    int     *copy_list;
    long    mistakes = 0;
    long    total_pairs = 0;
    int     i;
    int     j;

    copy_list = list_copy(list_a);
    if (size < 2)
        return (0.0);

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            total_pairs++;
            if (copy_list[i] > copy_list[j])
                mistakes++;
            j++;
        }
        i++;
    }
    free(copy_list);
    return ((double)mistakes / (double)total_pairs);
}
