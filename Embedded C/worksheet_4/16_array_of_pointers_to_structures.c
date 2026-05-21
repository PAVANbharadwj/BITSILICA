#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char name[10];
    int age;
}node;

int main()
{
    node*arr[3];
    int n=3;
    for(int i=0;i<n;i++)
    {
        arr[i]=(node*)malloc(1*sizeof(node));
        if(arr[i]== NULL)
        {
            printf("memory allocation failed");
            return -1;
        }
    }

    printf("enter elements to array: ");
    for(int i=0;i<n;i++)
    {
        printf("enter name: ");
        scanf("%s",&arr[i]->name);
        printf("enter age: ");
        scanf("%d",&arr[i]->age);
    }

    for(int i=0;i<n;i++)
    {
        printf("name: %s\t",arr[i]->name);
        printf("age: %d\n",arr[i]->age);
    }

    for(int i=0;i<n;i++)
    {
      free(arr[i]);
    }
}