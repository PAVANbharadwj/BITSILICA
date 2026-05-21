#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*prev;
    struct node*next;
}node;

node* head = NULL;

node* createnode(int data)
{
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

void insertend()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    
    node* new = createnode(data);
    
    if (head == NULL)
    {
        head = new;
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    new->prev = temp;
}

void printlist()
{
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void swapdata()
{
    node* temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        int t = temp->data;
        temp->data = temp->next->data;
        temp->next->data = t;
        temp = temp->next->next;
    }
}

int main()
{
    int a;
    printf("Enter number of nodes: ");
    scanf("%d", &a);

    for (int i = 0; i < a; i++)
        insertend();

    printf("\nBefore swapping:\n");
    printlist();

    swapdata();

    printf("\nAfter swapping:\n");
    printlist();
}