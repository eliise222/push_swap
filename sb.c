#include <stdio.h>
#include "push_swap.h"

int SB(int *b)
{
    int tmp;

    tmp = b[0];
    b[0] = b[1];
    b[1]  = tmp;
    return(1);
}

// int main()
// {
//     int b[] = {5, 3, 6, 7};
//     int i = 0;
//     printf("liste b avant sb\n");
//     while (i < 4)
//     {
//         printf("%d - ", b[i]);
//         i++;
//     }
//     int res = SB(b);
//     i = 0;
//     printf("\nliste b apres sb\n");
//     while (i < 4)
//     {
//         printf("%d - ", b[i]);
//         i++;
//     }
//     printf("\nresult = %d\n", res);
    

// }