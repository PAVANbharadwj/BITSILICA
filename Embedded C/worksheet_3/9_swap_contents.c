#include<stdio.h>

typedef struct node
{
    char name[10];
    int age;
}node;
void gatherdata(node*a)
{
    printf("enter name: ");
    scanf("%s",&a->name);
    printf("enter age: ");
    scanf("%d",&a->age);
}
void swapdata(node*a,node*b)
{
    node temp = *a;
    *a=*b;
    *b=temp;
}


int main()
{
    node a,b;
    gatherdata(&a);
    gatherdata(&b);

    swapdata(&a,&b);
    printf("a data: %s\t %d \n",a.name,a.age);
    printf("b data: %s\t %d",b.name,b.age);
}

