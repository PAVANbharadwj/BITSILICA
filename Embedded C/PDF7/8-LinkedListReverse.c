#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseBetween(struct Node* head, int left, int right) {
    if (!head || left == right) 
        return head;

    struct Node dummy;
    dummy.next = head;
    struct Node* prev = &dummy;

    for (int i = 1; i < left; i++)
        prev = prev->next;

    struct Node* curr = prev->next;
    for (int i = 0; i < right - left; i++) {
        struct Node* temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    return dummy.next;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, val, left, right;
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

    printf("Enter left and right positions to reverse: ");
    scanf("%d %d", &left, &right);

    head = reverseBetween(head, left, right);
    printf("Modified List: ");
    printList(head);

    return 0;
}