#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
} node;

node* createnode(int data)
{
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

node* createlist(node* head)
{
    int data;
    char ch;
    node *new, *temp;

    do {
        printf("Enter data: ");
        scanf("%d", &data);

        new = createnode(data);

        if (head == NULL)
        {
            head = new;
            temp = head;
        }
         else
        {
            temp->next = new;
            new->prev = temp;  
            temp = new;
        }

        printf("Enter 'y' to create another node, 'n' to stop: ");
        scanf(" %c", &ch); 

    } while (ch == 'y' || ch == 'Y');

    return head;
}

void printlist(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node* reverselist(node* head)
{
    node *current = head, *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;  
}

int main()
{
    node* head = NULL;
    head = createlist(head);

    printf("\nBefore reverse:\n");
    printlist(head);

    head = reverselist(head); 

    printf("After reverse:\n");
    printlist(head);

}