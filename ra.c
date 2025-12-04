#include <stdio.h>
#include "push_swap.h"

int RA(int *a, int size)
{
    int new_size;
    int i = 0;

    new_size = 0;

    while(i<size) 
    {
        if(a[i])
        {
            new_size ++;
        }
        i++;
    }

    i = 0;
    int mem = new_size - 1;
    new_size --;
    int tmp= a[new_size -1];
    a[new_size -1] = a[new_size];
    new_size -= 2;
    while(new_size  >= 0)
    {
        int tmo2 = tmp;
        tmp = a[new_size ];
        a[new_size ] =tmo2;
        new_size --;
    }
    a[mem] = tmp;
    return(1);
    
}

// int main()
// {
//     int taille = 8;
//     int a[] = {8, 1, 9, 7, 6, 0, 0, 0};
//     int b[] = {5, 3, 6, 7, 0, 0, 0, 0};
//     int i = 0;
//     int j = 0;
//     printf("liste a avant pa\n");
//     while (i < taille)
//     {
//         if(a[i])
//             printf("%d - ", a[i]);
//         i++;
//     }
//     printf("\nliste b avant pa\n");
//     while (j < taille)
//     {
//         if(b[j])
//             printf("%d - ", b[j]);
//         j++;
//     }
//      int res = RA(a, taille);
//     i = 0;
//     j = 0;
//      printf("\nliste a apres pa\n");
//     while (i < taille)
//     {
//         if(a[i])
//             printf("%d - ", a[i]);
//         i++;
//     }
//     printf("\nliste b apres pa\n");
//     while (j < taille)
//     {
//         if(b[j])
//             printf("%d - ", b[j]);
//         j++;
//     }
//     printf("\nresult = %d\n", res);
// }