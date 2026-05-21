#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*prev;
    struct node*next;
}node;
node*createlist()
{
    char choice;
    node*temp=NULL,*new=NULL,*head=NULL;
do
    {
        printf("enter data");
        new=(node*)malloc(sizeof(node));
        scanf("%d",&new->data);
        getchar();
        new->next=NULL;
        new->prev=NULL;
        if(head==NULL)
        {
            head=new;
            temp=head;
        }
        else
        {
            temp->next=new;
            new->prev=temp;
            temp=new;
        }
        printf("enter y to create new node n to not create node\n");
        scanf("%c",&choice);

    }while(choice == 'y' || choice == 'Y');
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
void reverselist(node*head)
{
    node*temp=head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}
int main()
{
    node*head=createlist();
    printlist(head);
    printf("\n");
    reverselist(head);
}