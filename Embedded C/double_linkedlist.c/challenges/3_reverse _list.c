#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*prev;
    struct node*next;
}node;
node* createnode(node*head,int data)
{
    node*new=(node*)malloc(sizeof(node));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    return new;
}
node*insertend(node*head)
{
    int data;
    char choice;
    node*new=NULL,*temp=NULL;
    do
    {
        printf("enter data: ");
        scanf("%d",&data);
        getchar();
        new=createnode(head,data);
            if(new==NULL)
            {
                printf("memory allocation failed ");
                return 0;
            }
        else if(head==NULL)
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
        printf("enter y to create new node n to not create node: ");
        scanf("%c",&choice);
    }while(choice == 'y'|| choice == 'Y');

return head;
}
void printlist(node* head)
{
    node*temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
node* reverselist(node*head)
{
    node*current=head;
    node*temp=NULL;
    while(current != NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp !=NULL)
    {
        head=temp->prev;
    }
    printf("\nlist reversed\n");
    printlist(head);
    return head;
}
void middle_element(node*head)
{
    node*slow=head;
    node*fast=head;
    while(fast != NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("\nmiddle element is %d",slow->data);
}
int main()
{
    node*head=NULL;
    head=insertend(head);
    printlist(head);
    head=reverselist(head);
    middle_element(head);
}
