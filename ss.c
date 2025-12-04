#include <stdio.h>
#include "push_swap.h"

int SS(int *a, int *b)
{
    SA(a);
    SB(b);
    return(1);
}

int main()
{
    int a[] = {8, 1, 9, 7};
    int b[] = {5, 3, 6, 7};
    int i = 0;
    int j = 0;
    printf("liste a avant ss\n");
    while (i < 4)
    {
        printf("%d - ", a[i]);
        i++;
    }
    printf("\nliste b avant ss\n");
    while (j < 4)
    {
        printf("%d - ", b[j]);
        j++;
    }
    int res = SS(a, b);
    i = 0;
    j = 0;
     printf("\nliste a apres ss\n");
    while (i < 4)
    {
        printf("%d - ", a[i]);
        i++;
    }
    printf("\nliste b apres sb\n");
    while (j < 4)
    {
        printf("%d - ", b[j]);
        j++;
    }
    printf("\nresult = %d\n", res);
    

}