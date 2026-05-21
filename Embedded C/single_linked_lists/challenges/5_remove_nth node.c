#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node* createlist(int n)
{
    struct node*temp=NULL,*new=NULL,*head=NULL;
    printf("enter data : ");
    for(int i=0;i<n;i++)
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
void printlist(struct node *head)
{
    struct node*temp=head;    
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void removenode(int n,struct node*head)
{
    struct node *temp = head;
    for (int i = 1; i < n - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Position out of range!\n");
        return;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
    printlist(head);
}
int main()
{
    int n,k;
    printf("enter how many nodes you need to create: ");
    scanf("%d",&n);
    struct node*head=NULL;
    head=createlist(n);
    printlist(head);
    printf("enter node to delete from last");
    scanf("%d",&k);
    k=n-k+1;
    removenode(k,head);
}