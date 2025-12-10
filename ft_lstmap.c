/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 23:17:57 by elise             #+#    #+#             */
/*   Updated: 2025/09/09 23:48:01 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, void	*(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_n;
	void	*new_content;

	new_list = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_n = ft_lstnew(new_content);
		if (new_n == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_n);
		lst = lst->next;
	}
	return (new_list);
}
