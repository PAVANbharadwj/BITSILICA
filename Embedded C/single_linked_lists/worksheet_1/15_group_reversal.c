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
struct Node* reverseInGroups(struct Node* head, int k)
{
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
        head->next = reverseInGroups(next, k);
    return prev;
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
    printf("Enter block size (k): ");
    scanf("%d", &k);
    printf("Original list: ");
    printList(head);
    head = reverseInGroups(head, k);
    printf("Reversed in blocks of %d: ", k);
    printList(head);
}