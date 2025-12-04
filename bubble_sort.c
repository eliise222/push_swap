#include <stdio.h>

void bubble_sort(int *a, int size)
{
     int i = 0;
    int j;
    int tmp;

    while (i < size - 1)
    {
        j = 0;

        while (j < size - 1 - i)
        {
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
            j++;
        }

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
    bubble_sort(a, taille);
    printf("\na apres sort \n");
    i = 0;
    while(i<taille)
    {
        printf("%d - ", a[i]);
        i++;
    }
}