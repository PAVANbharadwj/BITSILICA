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
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void printList(struct Node* head)
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void rotate(struct Node** head, int k)
 {
    if (*head == NULL || k == 0)
        return;
    struct Node* current = *head;
    int length = 1;
    while (current->next != NULL) 
    {
        current = current->next;
        length++;
    }
    current->next = *head;
    k = k % length;

    int steps = length - k;
    current = *head;
    for (int i = 1; i < steps; i++)
        current = current->next;

    *head = current->next;
    current->next = NULL;
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
    printf("Enter k (number of rotations): ");
    scanf("%d", &k);
    printf("Original list: ");
    printList(head);
    rotate(&head, k);
    printf("Rotated list:  ");
    printList(head);
}