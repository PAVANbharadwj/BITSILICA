#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* find(struct Node* head, int n) {
    struct Node *first = head, *second = head;

    for (int i = 0; i < n; i++) {
        if (!first) return NULL;
        first = first->next;
    }

    while (first) {
        first = first->next;
        second = second->next;
    }

    return second;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, pos, val;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter position from end: ");
    scanf("%d", &pos);

    struct Node* result = find(head, pos);
    if (result)
        printf("Node at position %d from end: %d\n", pos, result->data);
    else
        printf("Invalid position!\n");

    return 0;
}