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
void palindromecheck(node*head)
{
   int arr[100],i=0;
   node*temp=head;
    while(temp!= NULL)
    {
        arr[i++]=temp->data;
        temp=temp->next;
    }
    int start=0,end=i-1;
    while(start<end)
    {
        if(arr[start]!=arr[end])
            {
                printf("\nnot a palindrome");
                return;
            }
            start++;
            end--;
    }
    printf("\nlist is a palindrome");


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
    palindromecheck(head);
}