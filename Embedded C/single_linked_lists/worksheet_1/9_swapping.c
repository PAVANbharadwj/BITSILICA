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
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void swapKth(struct Node** head, int k)
{
    if (*head == NULL)
        return;
    int n = 0;
    struct Node* temp = *head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    if (k > n || (2 * k - 1) == n) 
        return;
    struct Node *x = *head, *x_prev = NULL;
    for (int i = 1; i < k; i++)
    {
        x_prev = x;
        x = x->next;
    }
    struct Node *y = *head, *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++)
    {
        y_prev = y;
        y = y->next;
    }
    if (x_prev)
        x_prev->next = y;
    if (y_prev)
        y_prev->next = x;
    struct Node* tempNext = x->next;
    x->next = y->next;
    y->next = tempNext;
    if (k == 1)
        *head = y;
    if (k == n)
        *head = x;
}
int main()
{
    struct Node* head = NULL;
    int n, val, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    printf("Original list: ");
    printList(head);
    swapKth(&head, k);
    printf("After swapping: ");
    printList(head);
}
