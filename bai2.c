#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int SNT(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void createProductList(struct Node* primeList, struct Node** productList, int n) {
    struct Node* ptr1 = primeList;
    while (ptr1 != NULL) {
        struct Node* ptr2 = ptr1;
        while (ptr2 != NULL) {
            int product = ptr1->data * ptr2->data;
            if (product < n) {
                insertAtEnd(productList, product);
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* primeList = NULL;
    struct Node* productList = NULL;
    int n;

    printf("Enter the upper limit for prime numbers: ");
    scanf("%d", &n);

    for (int i = 2; i < n; i++) {
        if (SNT(i)) {
            insertAtEnd(&primeList, i);
        }
    }

    printf("Prime numbers less than %d: ", n);
    printList(primeList);

    printf("Enter the maximum product value: ");
    scanf("%d", &n);

    createProductList(primeList, &productList, n);

    printf("Products of two prime numbers less than %d: ", n);
    printList(productList);

    return 0;
}
