#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printList(struct Node* head)
{
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* partition(struct Node* head, int x)
{
    struct Node *before = NULL, *beforeTail = NULL;
    struct Node *after = NULL, *afterTail = NULL;
    while (head)
    {
        struct Node* next = head->next;
        head->next = NULL;

        if (head->data < x)
        {
            if (before == NULL)
                before = beforeTail = head;
            else 
            {
                beforeTail->next = head;
                beforeTail = head;
            }
        } else 
        {
            if (after == NULL)
                after = afterTail = head;
            else 
            {
                afterTail->next = head;
                afterTail = head;
            }
        }
        head = next;
    }

    if (before == NULL)
        return after;
    beforeTail->next = after;
    return before;
}

int main() 
{
    struct Node* head = NULL;
    int n, val, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter list elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    printf("Enter partition value x: ");
    scanf("%d", &x);
    printf("Original list: ");
    printList(head);
    head = partition(head, x);

    printf("Reordered list: ");
    printList(head);
}