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
}
int main()
{
    t_list *n1 = malloc(sizeof(t_list));
    t_list *n2 = malloc(sizeof(t_list));
    t_list *n3 = malloc(sizeof(t_list));
    t_list *head;

    if (!n1 || !n2 || !n3)
        return (1);

    /* --- ASTUCE ICI --- */
    /* On force le int à rentrer dans le void* avec (void *) */
    /* Attention: on stocke la VALEUR dans l'ADRESSE. C'est un hack pratique pour tester. */
    n1->content = (void *)1;
    n2->content = (void *)2;
    n3->content = (void *)3;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    head = n1;


    printf("Avant : %ld -> %ld -> %ld\n", (long)head->content, (long)head->next->content, (long)head->next->next->content);

    head = reversenode(head);

    printf("Apres : %ld -> %ld -> %ld\n", (long)head->content, (long)head->next->content, (long)head->next->next->content);

    if ((long)head->content == 2 && (long)head->next->content == 1)
        printf("\n✅ SUCCESS\n");
    else
        printf("\n❌ FAIL\n");

    free(n1);
    free(n2);
    free(n3);
    return 0;
}

/*
int SA(int *a)
{
    int tmp;

    tmp = a[0];
    a[0] = a[1];
    a[1]  = tmp;
    return(1);
}*/

// int main()
// {
//     int a[] = {5, 3, 6, 7};
//     int i = 0;
//     printf("liste a avant sa\n");
//     while (i < 4)
//     {
//         printf("%d - ", a[i]);
//         i++;
//     }
//     int res = SA(a);
//     i = 0;
//     printf("\nliste a apres sa\n");
//     while (i < 4)
//     {
//         printf("%d - ", a[i]);
//         i++;
//     }
//     printf("\nresult = %d\n", res);
    

// }