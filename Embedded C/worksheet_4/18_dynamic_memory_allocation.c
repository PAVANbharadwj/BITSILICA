#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char name[10];
    int age;
}node;
void printdata(node*k);

int main()
{
    node*v= (node*) malloc(1*sizeof(node));
    printf("enter name: ");
    scanf("%s",v->name);
    printf("enter age: ");
    scanf("%d",&v->age);

    printdata(v);
    free(v);
}

void printdata(node*k)
{
    printf("name: %s",k->name);
    printf("\nage: %d",k->age);
}