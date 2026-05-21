#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;

void push(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->prev = NULL;
    new->next = head; 

    if (head != NULL)
        head->prev = new;

    head = new;
}

void pop()
{
    if (head == NULL) 
    {
        printf("\nStack is empty.\n");
        return;
    }

    node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("\nPopped element: %d\n", temp->data);
    free(temp);
}

void display()
{
    node *temp = head;
    printf("\nElements in stack (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    return 0;
}