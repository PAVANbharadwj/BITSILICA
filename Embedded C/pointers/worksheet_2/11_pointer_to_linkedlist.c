#include<stdio.h>
#include<stdlib.h>
struct stu
{
    int data;
    struct stu*next;
};
int main()
{
    int a;
    printf("enter no of nodes\n");
    scanf("%d",&a);
    struct stu*head=NULL,*new=NULL,*temp=NULL;
    temp=head;
    for(int i=0;i<a;i++)
    {
        new=(struct stu *)malloc(1*sizeof(struct stu));
        new->next=NULL;
        printf("enter data");
        scanf("%d",&new->data);
        if(head==NULL)
        {
            head=new;
            temp=head;
        }
        else
        {
            temp->next=new;
            temp=new;
        }
    }
    temp=head;
    for(int i=0;i<a;i++)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    free(new);
}
