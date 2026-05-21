#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void insert(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) 
    {       
        head = newNode;
        newNode->next = head; 
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;  
    }
}
void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    display();
}
