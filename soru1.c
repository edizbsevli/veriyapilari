#include <stdio.h>

int main() {
    int dizi[] = { 10, 20, 20 };
    int n = sizeof(dizi) / sizeof(dizi[0]);

 
    int eleman[10];
    int frekanslar[10];
    int sayac = 0;
    for (int i = 0; i < n; i++) {
        int eleman = dizi[i];
        int j;
        for (j = 0; j < sayac; j++) {
            if (eleman[j] == eleman) {
                frekanslar[j]++;
                break;
            }
        }
        if (j == sayac) {
            eleman[sayac] = eleman;
            frekanslar[sayac] = 1;
            sayac++;
        }
    }

 
    for (int i = 0; i < sayac; i++) {
        printf("%d -> %d\n", eleman[i], frekanslar[i]);
    }

    return 0;
}