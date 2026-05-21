#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char name[10];
    int age;
}node;
node* takedata();

int main()
{
    node*k=takedata();
    printf("name: %s",k->name);
    printf("\nage: %d",k->age);
}

node* takedata()
{

    node*v= (node*) malloc(1*sizeof(node));
    printf("enter name: ");
    scanf("%s",v->name);
    printf("enter age: ");
    scanf("%d",&v->age);

    return v;
}