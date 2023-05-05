#include <stdio.h>
int main()
{
    int swap;
    int a[] = { 4,2,9,8 };
    int b[] = { 1,5,7,9 };
    int c[8];

    for (int i = 0; i < 4; i++)
    {
        c[i] = a[i];
    }

    for (int i = 4; i < 8; i++)
    {
        c[i] = b[i - 4];
    }
    printf("Birlestirilmis Dizi: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\nSiralama Yapiliyor!");
    printf("\nSiralama Yapildi: ");

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7 - i; j++)
        {
            if (c[j] > c[j + 1])
            {
                swap = c[j];
                c[j] = c[j + 1];
                c[j + 1] = swap;

            }
        }
    }

    for (int i = 0; i < 8; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}