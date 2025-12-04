#include <stdio.h>
#include "push_swap.h"

int PB(int *a, int *b, int size)
{
    int i = 1;
    int tmp = b[0];
    b[0] = a[0];
    while (i < size)
    {
         int tmp2 = b[i];
         b[i] = tmp;
         tmp = tmp2;
         i++;
    }
    int j = 0;
    while(j < size)
    {
        if(a[j])
        {
            a[j] = a[j+1];
        }
        j++;
    }
    return(1);
}

int main()
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
    int res = PB(a, b, taille);
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
}