#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* createlist(int a)
{
    struct node*head=NULL,*temp=NULL,*new=NULL;
    head=temp;
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
void splitlist(struct node*head,int n)
{
    struct node *new=NULL,*temp=head;
    for(int i=0;i<n-1;i++)
    {
        temp=temp->next;
    }
    new=temp->next;
    temp->next=NULL;
    printf("\nfirst part: ");
    printlist(head);
    printf("second part: ");
    printlist(new);

}
int main()
{
    int a;
    struct node*head=NULL;
    printf("enter no of nodes to create");
    scanf("%d",&a);
    head=createlist(a);

    printlist(head);
    int size=a/2;
    splitlist(head,size);
}