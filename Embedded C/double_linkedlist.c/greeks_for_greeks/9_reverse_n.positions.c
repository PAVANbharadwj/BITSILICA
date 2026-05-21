#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertEnd(int data) 
{
    struct node* newNode = createNode(data);
    if (head == NULL) 
    {
        head = newNode;
        return;
    }
    struct node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void reverseSublist(int m, int n) 
{
    if (head == NULL || m == n) return;

    struct node* temp = head;
    int pos = 1;

    while (temp && pos < m)
    {
        temp = temp->next;
        pos++;
    }
    struct node* start = temp;

    while (temp && pos < n) 
    {
        temp = temp->next;
        pos++;
    }
    struct node* end = temp;

    while (start != end && start->prev != end)
     {
        int t = start->data;
        start->data = end->data;
        end->data = t;

        start = start->next;
        end = end->prev;
     }
}

void display()
{
    struct node* temp = head;
    while (temp)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);

    printf("Original list:\n");
    display();

    reverseSublist(2, 4);

    printf("\nAfter reversing from 2 to 4:\n");
    display();
}