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
    printf("first half");
     for(int i=0;i<size/2;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\nlast half");
     for(int i=size/2;i<size;i++)
    {
        printf(" %d ",arr[i]);
    }
    
}