#include <stdio.h>
#include "push_swap.h"

int SA(int *a)
{
    int tmp;

    tmp = a[0];
    a[0] = a[1];
    a[1]  = tmp;
    return(1);
}

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