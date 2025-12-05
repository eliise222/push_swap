#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"
t_list    *reversenode(t_list* a)
{
    t_list *temp;
    t_list *b;
    if (a == NULL || a->next == NULL)
        return (a);
    b = a->next;
    temp = b->next;
    b->next = a;
    a->next = temp;
    return(b);
} // on inverse le premier et le deuxieme element de la liste chainee

static void	reverse_all(t_list	**a)
{
	t_list	*last;
	t_list	*blast;
	blast = *a;

	if(*a == NULL || (*a)->next == NULL || a == NULL)
		return;
	while(blast->next->next != NULL) //jusque avant dernier
		blast = blast->next;

	last = blast->next;//dernier
	last->next = *a;//dernier devient premier
	blast->next = NULL;//avant dernier devient dernier

	*a = last;// nouveau premier element liste
}
