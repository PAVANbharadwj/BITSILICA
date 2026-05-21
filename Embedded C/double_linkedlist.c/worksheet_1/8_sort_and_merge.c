#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
    int data;
    struct node *prev, *next;
} node;

node* createNode(int data) 
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
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

void sortList(node* head) 
{
    node* i;
    node* j;
    int temp;
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
         {
            if (i->data > j->data)
             {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
node* mergeLists(node* head1, node* head2) 
{
    node* merged = NULL;
    node* tail = NULL;
    
    while (head1 != NULL && head2 != NULL)
    {
        node* newNode;
        if (head1->data <= head2->data)
         {
            newNode = createNode(head1->data);
            head1 = head1->next;
        }
         else
        {
            newNode = createNode(head2->data);
            head2 = head2->next;
        }

        if (merged == NULL)
         {
            merged = newNode;
            tail = newNode;
         }
         else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    while (head1 != NULL)
    {
        node* newNode = createNode(head1->data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        node* newNode = createNode(head2->data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        head2 = head2->next;
    }

    return merged;
}
int main()
{
    node *head1 = NULL, *head2 = NULL, *merged = NULL;
    int n1, n2, data;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) 
    {
        printf("Enter data: ");
        scanf("%d", &data);
        head1 = insertEnd(head1, data);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        head2 = insertEnd(head2, data);
    }

    printf("\nList 1 before sorting: ");
    printList(head1);
    printf("List 2 before sorting: ");
    printList(head2);

    sortList(head1);
    sortList(head2);

    printf("\nList 1 after sorting: ");
    printList(head1);
    printf("List 2 after sorting: ");
    printList(head2);

    merged = mergeLists(head1, head2);

    printf("\nMerged Sorted List: ");
    printList(merged);
}