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
void rearrangeEvenAfterOdd(struct Node** head) 
{
    if (*head == NULL || (*head)->next == NULL)
    return;
    struct Node *odd = *head;
    struct Node *even = (*head)->next;
    struct Node *evenStart = even;
    while (even != NULL && even->next != NULL) 
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
}
int main() 
{
    struct Node* head = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    printf("Original list: ");
    printList(head);
    rearrangeEvenAfterOdd(&head);
    printf("Rearranged list (odd positions first): ");
    printList(head);
}