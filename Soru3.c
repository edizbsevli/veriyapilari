#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print(struct node* head) {
    while (head != NULL) {
        printf("%d,", head->data);
        head = head->next;
    }
}

void VerileriEkle(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct node* BirleşmişListe(struct node* list1, struct node* list2) {
    struct node* list3 = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            VerileriEkle(&list3, list1->data);
            list1 = list1->next;
        }
        else {
            VerileriEkle(&list3, list2->data);
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        VerileriEkle(&list3, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        VerileriEkle(&list3, list2->data);
        list2 = list2->next;
    }

    return list3;
}

int main() {
    struct node* list1 = NULL;
    VerileriEkle(&list1, 1);
    VerileriEkle(&list1, 3);
    VerileriEkle(&list1, 4);
    VerileriEkle(&list1, 5);

    struct node* list2 = NULL;
    VerileriEkle(&list2, 2);
    VerileriEkle(&list2, 4);
    VerileriEkle(&list2, 6);
    VerileriEkle(&list2, 8);

    printf("List 1: ");
    print(list1);
    printf("\nList 2: ");
    print(list2);

    struct node* list3 = BirleşmişListe(list1, list2);

    printf("\nList3: ");
    print(list3);

    return 0;
}