#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* createlist(int a)
{
    struct node*new=NULL,*temp=NULL,*head=NULL;
    printf("enter data");
    for(int i=0;i<a;i++)
    {
        new=(struct node*)malloc(1*sizeof(struct node));
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            temp=head;
        }
        else
        {
            temp->next=new;
            temp=new;
        }
    }
return head;
}
void printlist(struct node*head)
{
   struct node*temp=head;
   
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void middle_element(struct node*head,int a)
{
    struct node*temp=head;
    a=a/2;
    for(int i=0;i<a;i++)
    {
        temp=temp->next;
    }
    printf("the middle element is %d",temp->data);
}

int main()
{
    int a;
    printf("enter the number if nodes");
    scanf("%d",&a);
    struct node*head=createlist(a);
    middle_element(head,a);
}