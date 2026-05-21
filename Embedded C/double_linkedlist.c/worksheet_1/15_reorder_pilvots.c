#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
    struct node*prev;
}node;
node*createlist(int data)
{
    node*new=NULL;
    new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
node*insertend(node*head)
{
    int data;
    printf("enter data");
    scanf("%d",&data);
    node*new=NULL,*temp=NULL;
    new=createlist(data);
    if(head==NULL)
    {
        head=new;
        temp=head;
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
void reorder(node*head)
{
    node*slow=head;
    node*fast=head;
    node*temp=head;
    int t;
    while(temp != NULL)
    {
        slow=head->next;
        fast=head->next->next;
        if(slow->data != fast->data)
        {
            t=slow->data;
            slow->data=fast->data;
            fast->data=t;
        }
        temp=temp->next;
    }
    printf("\nafter re-order");
    printlist(head);
}
int main()
{
    int n;
    node*head=NULL;
    printf("enter no of nodes to create: ");
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        head=insertend(head);    
    }
    printlist(head);
    reorder(head);
}