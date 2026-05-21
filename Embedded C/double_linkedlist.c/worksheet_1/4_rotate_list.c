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
void rotatelist(node* head, int k) 
{
    if (!head || k == 0)
        return;
    node* temp = head;
    int len = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    temp->next = head;
    head->prev = temp;
    k = k % len;
    if (k == 0) 
    {
        temp->next = NULL;
        head->prev = NULL;
        return ;
    }
    node* newTail = head;
    for (int i = 1; i < k; i++)
        newTail = newTail->next;

    node* newHead = newTail->next;

    newTail->next = NULL;
    newHead->prev = NULL;

    printf("\nafter rotation ");
    printlist(newHead);
}

int main()
{
    char choice;
    node*head=NULL;
    do
    {
        head=insertend(head);
        printf("enter y to create another node n to not create node: ");
        scanf("%c",&choice);
    }while(choice == 'y' || choice =='Y');
    printlist(head);
    int k;
    printf("enter steps to rotate list");
    scanf("%d",&k);
    rotatelist(head,k);
}