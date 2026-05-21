#include<stdio.h>
int main()
{
    int arr[5];
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("reversed array ");
    for(int i=size-1;i>=0;i--)
    {
    printf("%d ",arr[i]);
    }
}