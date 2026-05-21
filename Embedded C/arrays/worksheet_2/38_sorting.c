#include<stdio.h>
int main()
{
    int arr[6],temp;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements into array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    for(int i=0;i<size;i++)
    {
       for(int j=0;j<size-i-1;j++)
       {
        if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}