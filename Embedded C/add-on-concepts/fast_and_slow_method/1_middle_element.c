#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
}node;

node* createnode(node*head)
{
    int data;
    printf("enter data: ");
    scanf("%d",&data);
    node*new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    
    if(head == NULL)
    {
        head=new;
        return head;
    }
    node*temp=head;
    while(temp->next != NULL)
    temp=temp->next;

    temp->next=new;
  
    return head;
}
void printlist(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
    printf("%d ",temp->data);
    temp=temp->next;
    }
}
void middleelement(node*head)
{
    node*fast=head,*slow=head;
    
    while(fast !=NULL && fast->next != NULL)
    {
    fast=fast->next->next;
    slow=slow->next;
    }
    printf("\nThe middle element is %d",slow->data);
}

int main()
{
    int a;
    printf("enter no of nodes to create: ");
    scanf("%d",&a);
    node*head=NULL;
    for(int i=0;i<a;i++)
    {
        head=createnode(head);
    }
    printlist(head);
    middleelement(head);
}



