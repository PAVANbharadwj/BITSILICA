#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*link;
}node;

node*top=NULL;

node* push(int x)
{
    node*new=(node*)malloc(sizeof(node));
    new->data=x;
    new->link=top;
    top=new;

}

void display(node*top)
{
    node*temp=top;
    if(temp == NULL)
    {
        printf("stack is empty");
        exit(0);
    }
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}

void peek()
{
    if(top == NULL)
    {
        printf("the stack is empty");
        return;
    }
    printf("\nthe peak element is %d",top->data);
}

void pop()
{
    if(top == NULL)
    {
        printf("stack is empty");
        return;
    }
    node*temp=top;
    top=top->link;
    free(temp);
    printf("\nelement get popped\n");
}

int main()
{
    push(3);
    push(4);
    push(5);
    push(9);
    display(top);
    peek();
    pop();
    display(top);
    pop();
    display(top);
}