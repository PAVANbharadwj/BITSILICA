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

void splitList(node* head) 
{
    if (head == NULL) return;

    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* second = slow->next;
    if (second != NULL)
        second->prev = NULL;
    slow->next = NULL;

    printf("\nFirst half: ");
    printList(head);

    printf("Second half: ");
    printList(second);
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

    splitList(head);
}
