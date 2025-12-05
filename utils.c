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

t_list  *get_last_node(t_list *head)
{
    if (head == NULL)
        return (NULL);
    while (head->next != NULL)
        head = head->next;
    return (head);
} //on recupere le dernier noeud de la liste chainee
