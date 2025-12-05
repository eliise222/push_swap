#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

void  pb(t_list   **a, t_list  **b)
{
    t_list  *temp;
    if (*a == NULL)
        return;
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    write(1, "pb\n", 3);
}

void  pa(t_list   **b, t_list  **a)
{
    t_list  *temp;
    if (*b == NULL)
        return;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    write(1, "pa\n", 3);
}

/*int PA(int *a, int *b, int size)
{
    int i = 1;
    int tmp = a[0];
    a[0] = b[0];
    while (i < size)
    {
         int tmp2 = a[i];
         a[i] = tmp;
         tmp = tmp2;
         i++;
    }
    int j = 0;
    while(j < size)
    {
        if(b[j])
        {
            b[j] = b[j+1];
        }
        j++;
    }
    return(1);
}*/
