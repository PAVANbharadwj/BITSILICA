#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
    struct node*prev;
}node;
node* createnode(int data)
{
    node*new=NULL;
    new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
node* insertend(node*head)
{
    int data;
        printf("enter data");
        scanf("%d",&data);
        getchar();
        node*new=NULL,*temp=NULL;
        new=createnode(data);
        if(head == NULL)
        {
            head=new;
            temp=head;
        }
        else
        {
           temp=head;
           while(temp->next !=NULL)
                temp=temp->next;

                temp->next=new;
                new->prev=temp;
        }
        return head;
}
void printlist(node*head)
{
    node*temp=head;
    while(temp !=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

}
void swapelements(node* head, int p1,int p2) 
{
    int count=1;
    node*temp=head,*first=NULL,*second=NULL;
    
    while(temp != NULL)
    {
        if(count==p1)
        {
            first=temp;
        }
        if(count==p2)
        {
            second=temp;
        }
        count++;
        temp=temp->next;
    }
    if(first == NULL && second == NULL)
    {
        printf("invalid positions\n enter valid positions");
        return;
    }
    int t=first->data;
    first->data=second->data;
    second->data=t;
    printf("\nafter swapping: ");
    printlist(head);
}
int main()
{
    char choice;
    node*head=NULL;
    do
    {
        head=insertend(head);
        printf("enter y to create another node n to not create node: ");
        scanf(" %c",&choice);
    }while(choice == 'y' || choice =='Y');
    printlist(head);
    int p1,p2;
    printf("enter positions to swap : ");
    scanf("%d%d",&p1,&p2);
    swapelements(head,p1,p2);
}