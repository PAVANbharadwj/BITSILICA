#include<stdio.h>
int main()
{
    int arr[3],arr1[3],temp[10],t=0;
    int size=sizeof(arr1)/sizeof(arr1[0]);
    printf("enter the elements into 1st array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("enter the elements into 2st array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr1[i]);
    }
    for(int i=0;i<size;i++)
    {
        temp[t]=arr[i];
        t++;
    }
for(int i=0;i<size;i++)
    {
        temp[t]=arr1[i];
        t++;
    }
for(int i=0;i<t;i++)
    {
        printf("%d ",temp[i]);
    }
}