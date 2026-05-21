#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int marks;
} node;

int main()
{
    node *arr[5];

    printf("Enter marks:\n");

    for(int i=0;i<5;i++)
    {
        arr[i] = (node*) malloc(sizeof(node)); 
        scanf("%d", &arr[i]->marks);
    }

    int totalmarks = 0;

    for(int i=0;i<5;i++)
    {
        totalmarks += arr[i]->marks;
        free(arr[i]);
    }
    
    int average = totalmarks / 5;

    printf("The average marks is %d\n", average);
}
