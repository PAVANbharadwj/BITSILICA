#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*prev;
    struct node*next;
}node;
node* createnode(int data)
{
    node*new=NULL;
    new=(node*)malloc(sizeof(node));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;

    return new;
}
node* insertend(node* head)
{
    int data;
    node*temp=NULL,*new=NULL;
    printf("enter data: ");
    scanf("%d",&data);
    new=createnode(data);
    if(head == NULL)
    {
        return new;
    }
    else
    {
        temp=head;
        while(temp->next != NULL)
        temp=temp->next;
        
        temp->next=new;
        new->prev=temp;
    }
    return head;
}
void printlist(node*head)
{
    node*temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void middlenode(node* head)
{
    node*slow=head;
    node*fast=head;
    while(fast != NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("\nthe middle node in the list is %d ",slow->data);
}
int main()
{
    int a;
    node*head=NULL;
    printf(" enter how many nodes you need to create: ");
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        head=insertend(head);
    }
    printlist(head);
    middlenode(head);
}