#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[5];
    printf("enter the elements to array");
    for(int i=0;i<5;i++)
    scanf("%d",&arr[i]);
    int*ptr=(int*)malloc(5*sizeof(int));
    int j=0;
    for(int i=4;i>=0;i--)
    {
        ptr[j]=arr[i];
        j++;
    }
    for(int i=0;i<5;i++)
    {
        printf("%d\t",ptr[i]);
    }
    free(ptr);
}