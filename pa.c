#include <stdio.h>
#include "push_swap.h"

int PA(int *a, int *b, int size)
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
/*int main()
{
    int taille = 8;
    int a[] = {8, 1, 9, 7, 0, 0, 0, 0};
    int b[] = {5, 3, 6, 7, 0, 0, 0, 0};
    int i = 0;
    int j = 0;
    printf("liste a avant pa\n");
    while (i < taille)
    {
        if(a[i])
            printf("%d - ", a[i]);
        i++;
    }
    printf("\nliste b avant pa\n");
    while (j < taille)
    {
        if(b[j])
            printf("%d - ", b[j]);
        j++;
    }
    int res = PA(a, b, taille);
    i = 0;
    j = 0;
     printf("\nliste a apres pa\n");
    while (i < taille)
    {
        if(a[i])
            printf("%d - ", a[i]);
        i++;
    }
    printf("\nliste b apres pa\n");
    while (j < taille)
    {
        if(b[j])
            printf("%d - ", b[j]);
        j++;
    }
    printf("\nresult = %d\n", res);
}*/