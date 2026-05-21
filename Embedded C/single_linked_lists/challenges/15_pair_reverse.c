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
struct Node* pairwiseReverse(struct Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct Node* prev = head;
    struct Node* curr = head->next;
    head = curr;
    while (1)
     {
        struct Node* next = curr->next;
        curr->next = prev;
        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }

    return head;
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
    head = pairwiseReverse(head);
    printf("List after pairwise reversal: ");
    printList(head);
}