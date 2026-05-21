#include<stdio.h>
#include<stdlib.h>
struct node
{
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
void movenode(struct node*head,int n)
{
    if (head == NULL || (head)->next == NULL)
        return;
    struct node *secondLast = head;
    
    while (secondLast->next->next != NULL)
        secondLast = secondLast->next;
    
    struct node *last = secondLast->next;
    secondLast->next = NULL;
    last->next = head;
    head = last;
    printf("\nafter moving: ");
    printlist(head);
}
int main()
{
    int a;
    printf("enter the number if nodes");
    scanf("%d",&a);
    struct node*head=createlist(a);
    printf("before moving");
    printlist(head);
    movenode(head,a);
}