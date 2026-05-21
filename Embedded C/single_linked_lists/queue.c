#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*link;
}node;
node*head=NULL;
node*tail=NULL;
void enqueue(int x)
{
    node*new=(node*)malloc(sizeof(node));
    new->data=x;
    new->link=NULL;
    if(head==NULL && tail == NULL)
    {
        head=tail=new;
    }
    else
    {
        tail->link=new;
        tail=new;
    }
}
void display()
{
    node*temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
void peek()
{
    printf("\nfirst element: %d",head->data);
}

void dequeue()
{
    node*temp=head;
    if(head== NULL)
    {
        printf("queue is empty");
        return;
    }
    else
    {
        temp=head;
        head=head->link;
        free(temp);
        printf("\nlist is dequeued\n");
    }

}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    peek();
    dequeue();
    enqueue(9);
    display();
}