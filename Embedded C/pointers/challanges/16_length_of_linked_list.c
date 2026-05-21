#include<stdio.h>
#include<stdlib.h>
struct stu
{
    int num;
    struct stu*next;
};
void getlength(struct stu **head);
int main()
{
    int a;
    printf("enter no of nodes to create\n");
    scanf("%d",&a);
    struct stu*head=NULL,*temp=NULL,*newnode=NULL;
    head=temp;
    for(int i=0;i<a;i++)
    {
        newnode=(struct stu*) malloc(1*sizeof(struct stu));
        printf("enter the value ");
        scanf("%d",&newnode->num);
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    newnode->next=NULL;
    temp=head;
    for(int i=0;i<a;i++)
    {
        printf("%d ",temp->num);
        temp=temp->next;
    }
    getlength(&head);
}
void getlength(struct stu **head)
{
   int count=0;
    struct stu *temp=*head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("\nlength of linked list is %d",count);
}