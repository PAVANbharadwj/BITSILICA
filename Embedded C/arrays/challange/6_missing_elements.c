#include<stdio.h>
int main()
{
    int arr[6];
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    for(int i=0;i<size-1;i++)
    {
    if((arr[i+1]-arr[i])!=1)
    {
        printf("the missing element is:%d\n",arr[i]+1);
    }
    }
}