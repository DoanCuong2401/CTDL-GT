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

struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    struct Node* tmp = head;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = newNode;
    return head;
}

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isPresent(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) return 1;
        temp = temp->next;
    }
    return 0;
}

void findBlumPairs(struct Node* head, int n) {
    struct Node* p1 = head;
    int count = 0;
    while (p1 != NULL) {
        struct Node* p2 = p1->next;
        while (p2 != NULL) {
            int sum = p1->data + p2->data;
            if (sum < n && isPresent(head, sum)) {
                printf("(%d, %d) ", p1->data, p2->data);
                count++;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    if (count == 0) {
        printf("No valid pairs found");
    }
    printf("\n");
}

int main() {
    struct Node* primeList = NULL;
    struct Node* productList = NULL;
    int n, m;

    // Limit cho Blum
    printf("limit for Blum numbers (N): ");
    scanf("%d", &n);
    printf("number check (M): ");
    scanf("%d", &m);

    // Tạo list Blum
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            struct Node* tmp = primeList;
            while (tmp != NULL) {
                int product = tmp->data * i;
                if (product >= n) break;
                productList = insert(productList, product);
                tmp = tmp->next;
            }
            int square = i * i;
            if (square < n) {
                productList = insert(productList, square);
            }
            primeList = insert(primeList, i);
        }
    }

    // In ra số Blume
    printf("Blum numbers less than %d:\n", n);
    printList(productList);

    // Yêu cầu 1
    printf("Pairs of Blum numbers whose sum is also a Blum number:\n");
    findBlumPairs(productList, n);

    // Yêu cầu 2
    if (isPresent(productList, m)) {
        printf("%d is a Blum number\n", m);
    } else {
        printf("%d is not a Blum number\n", m);
    }

    return 0;
}
