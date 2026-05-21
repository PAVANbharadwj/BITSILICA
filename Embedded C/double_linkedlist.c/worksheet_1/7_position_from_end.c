#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
} node;
node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
node* insertEnd(node* head, int data)
{
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
void nthFromEnd(node* head, int n)
 {
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    int count = 0;
    node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (n > count || n <= 0)
    {
        printf("Invalid n: list has only %d nodes.\n", count);
        return;
    }
    temp = head;
    for (int i = 0; i < count - n; i++)
    {
        temp = temp->next;
    }

    printf("Result: %d\n", temp->data);
}

int main()
{
    node* head = NULL;
    int num, data, n;

    printf("Enter number of nodes: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("List: ");
    printList(head);

    printf("Enter n (node from end): ");
    scanf("%d", &n);

    nthFromEnd(head, n);

    return 0;
}
