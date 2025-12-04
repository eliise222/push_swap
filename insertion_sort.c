#include <stdio.h>

void insertion_sort(int *a, int size)
{
    int i = 1;
    int j = 0;
    int tmp;

    while(i<size)
    {
        j = i;
        tmp = a[i];

        while(j>0 && a[j-1] > tmp)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = tmp;
        i++;
    }

}

int main()
{
    int taille = 8;
    int a[] = {23, 1, 10, 5, 18, 3, 12, 19};
    printf("a avant sort \n");
    int i = 0;
    while(i<taille)
    {
        printf("%d - ", a[i]);
        i++;
    }
    insertion_sort(a, taille);
    printf("\na apres sort \n");
    i = 0;
    while(i<taille)
    {
        printf("%d - ", a[i]);
        i++;
    }
}