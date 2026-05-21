#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;

node* createnode(int data) 
{
    node* new = (node*)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

node* insertend(node* head)
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    node* new = createnode(data);
    if (head == NULL) 
    {
        return new;
    }
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;

    return head;
}

void printlist(node* head)
{
    node* temp = head;
    printf("\nList: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    char choice;
    node* head = NULL;
    do {
        head = insertend(head);
        printf("Press y to add another node, n to stop: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printlist(head);

    return 0;
}
