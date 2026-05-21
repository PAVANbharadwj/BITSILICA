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
    printf("even numbers");
     for(int i=0;i<size;i++)
    {
        if(arr[i]%2==0)
        printf(" %d ",arr[i]);
    }
    printf("\nodd numbers");
     for(int i=0;i<size;i++)
    {
        if((arr[i]%2)!=0)
        printf(" %d ",arr[i]);
    }
    
}