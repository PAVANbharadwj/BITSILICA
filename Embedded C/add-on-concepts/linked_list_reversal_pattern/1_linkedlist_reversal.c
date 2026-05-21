#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
}node;
node* createnode(node*head)
{
    int a;
    printf("enter data: ");
    scanf("%d",&a);
    node*new=(node*)malloc(1*sizeof(node));
    new->data=a;
    new->next=NULL;
    if(head == NULL)
    {
        head=new;
        return new;
    }
        node*temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
    
        temp->next=new;
    return head;
}
void printlist(node* head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
node* reverserange(node* head, int m, int n) 
{
    if(head == NULL || m == n)
    return head;

    node* prev = NULL;
    node* current = head;

    for(int i = 1; i < m; i++)
    {
        prev = current;
        current = current->next;
    }

    node* connection = prev;
    node* tail = current;
    node* next = NULL;

    for(int i = 0; i < n - m + 1; i++)
     {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
     }

    if(connection != NULL)
        connection->next = prev;
    else
        head = prev;

    tail->next = current;
    return head;
}
int main()
{
    int a;
    int n,m;
    
    printf("enter the size of list: ");
    scanf("%d",&a);
    node*head=NULL;
    
    for(int i=0;i<a;i++)
    {
        head=createnode(head);
    }
    
    printlist(head);
    printf("enter node to reverse");
    scanf("%d %d",&n,&m);
    
    head=reverserange(head,n,m);
    printf("after reverse\n");
    printlist(head);
}