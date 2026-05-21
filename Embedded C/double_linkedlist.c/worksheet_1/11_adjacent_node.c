#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
node* insertEnd(node* head)
 {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
void printList(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
node* swapAdjacent(node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node* curr = head;
    node* newHead = head->next;

    while (curr != NULL && curr->next != NULL) 
    {
        node* first = curr;
        node* second = curr->next;
        node* nextPair = second->next;

        second->prev = first->prev;
        if (second->prev)
            second->prev->next = second;

        second->next = first;
        first->prev = second;

        first->next = nextPair;
        if (nextPair)
            nextPair->prev = first;

        curr = nextPair;
    }
    return newHead;
}
int main() 
{
    node* head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        head = insertEnd(head);

    printf("\nOriginal list: ");
    printList(head);

    head = swapAdjacent(head);

    printf("After swapping adjacent nodes: ");
    printList(head);

    return 0;
}