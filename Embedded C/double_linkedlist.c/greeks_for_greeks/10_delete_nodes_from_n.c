#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*prev;
    struct node*next;
}node;
node* deletenodes(node *head, int pos, int count, int size) ;
node* createnode(int data)
{
    node*new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
node* insertend (node* head)
{
    int data;
    printf("enter data: ");
    scanf("%d",&data);
    node*new=createnode(data);
    if(head==NULL)
    {
        return new;
    }
        node*temp=head;
        while(temp->next != NULL)
        temp=temp->next;
        
        temp->next=new;
        new->prev=temp;
    

    return head;
}
void printlist(node*head)
{
    node*temp=head;
    while(temp != NULL)
    {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("null\n");
}
node* deletenodes(node *head, int pos, int count, int size) 
{
    if (head == NULL || pos < 1 || pos > size)
    {
        printf("Invalid position.\n");
        return head;
    }
    node *temp = head;
    int i;
    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return head;
    for (i = 0; i < count && temp != NULL; i++)
    {
        node *toDelete = temp;
        temp = temp->next;

    if (toDelete->prev != NULL)
            toDelete->prev->next = toDelete->next;
        else
            head = toDelete->next;

        if (toDelete->next != NULL)
            toDelete->next->prev = toDelete->prev;

        free(toDelete);
    }
    
    printf("Deleted %d nodes starting from position %d.\n", count, pos);
    return head;
}

int main()
{
    int a;
    printf("enter the size of list ");
    scanf("%d",&a);

    node*head=NULL;
    for(int i=0;i<a;i++)
    {
        head=insertend(head);
    }
    printlist(head);

    int node,y;

    printf("from which node you need to delete: ");
    scanf("%d",&node);

    printf("how many nodes to delete: ");
    scanf("%d",&y);

    head=deletenodes(head,node,y,a);
    printlist(head);
}