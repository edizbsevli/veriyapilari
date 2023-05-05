#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Kuyruk yap�s� i�in tan�mlama
struct Queue {
    char data[MAX_SIZE];
    int front, rear;
};

// Yeni bir kuyruk olu�turur
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Kuyrukta eleman var m� yok mu kontrol eder
int isEmpty(struct Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Kuyrukta eleman ekler
void enqueue(struct Queue* q, char c) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Kuyruk dolu!\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = c;
    if (q->front == -1) {
        q->front = 0;
    }
}

// Kuyrukta eleman ��kar�r
char dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Kuyruk bo�!\n");
        return '\0';
    }
    char c = q->data[q->front];
    q->front++;
    return c;
}

// Biti�ik kopyalar� kald�ran fonksiyon
void removeDuplicates(char* str) {
    int n = strlen(str);
    struct Queue* q = createQueue();
    int i = 0;
    while (i < n) {
        // E�er kuyruk bo�sa veya son eleman kuyruktaki son elemanla ayn� de�ilse
        // eleman� kuyru�a ekler
        if (isEmpty(q) || str[i] != q->data[q->rear]) {
            enqueue(q, str[i]);
            i++;
        }
        else {
            // Son elemanla ayn�ysa, kuyruktan t�m biti�ik kopyalar� ��kar�r
            while (i < n && str[i] == q->data[q->rear]) {
                i++;
            }
            q->rear--;
        }
    }
    // Yeni olu�an dizi kuyrukta depolan�r
    i = q->front;
    while (i <= q->rear) {
        str[i - q->front] = q->data[i];
        i++;
    }
    str[i - q->front] = '\0';
    free(q);
}

// Test etmek i�in main fonksiyonu
int main() {
    char str[MAX_SIZE];
    printf("Dizi girin: ");
    scanf("%s", str);
    removeDuplicates(str);
    printf("Sonu�: %s\n", str);
    return�0;
}