#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
    struct node*prev;
}node;
node*head=NULL;
node*tail=NULL;
void enqueue(int data)
{
    node*new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(head== NULL && tail == NULL)
    {
        head=tail=new;
    }
    else
    {
        tail->next=new;
        new->prev=tail;
        tail=new;

    }
}
void display()
{
    node*temp=head;
    printf("the elements in the list are: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void dequeue()
{
    if(head == NULL)
    {
        printf("list is empty");
        return;
    }

    node*temp=head;
    head=head->next;
    free(temp);
    head->prev=NULL;
}
void peek()
{
    printf("the peek element in queue is %d\n",head->data);
}
int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(20);
    display();
    peek();
    dequeue();
    peek();
    enqueue(50);
    display();
}