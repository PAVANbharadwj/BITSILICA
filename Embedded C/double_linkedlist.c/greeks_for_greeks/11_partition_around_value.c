#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*prev;
    struct node*next;
}node;
node*head = NULL;
node* createnode(int data)
{
    node*new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;

    return new;
}
void insertend()
{
    int data;
    printf("enter data");
    scanf("%d",&data);
    node*new=createnode(data);
    if(head == NULL)
    {
        head=new;
        return;
    }
    node*temp=head;
    while (temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
    temp=new;
}
void printlist()
{
    node*temp=head;
    
    while(temp !=NULL)
    {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL ");
}
void aroundvalue()
{
    node*temp=head;
    int x;
    for(node* i=head;i != NULL;i = i->next)
        {
            for(node* j = i->next;j != NULL ;j = j->next)
            {
                if( i->data > j->data)
                {
                    x=i->data;
                    i->data=j->data;
                    j->data=x;
                }
            }
        }
        printf("\nafter around value\n");
        printlist();
}
int main()
{
    int a;
    printf("enter the size of list");
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        insertend();
    }
    printlist();
    aroundvalue();
}