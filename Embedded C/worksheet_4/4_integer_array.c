#include<stdio.h>
void zeros_to_start(int*arr,int n)
{
    int result[n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)    
        result[k++]=arr[i];
    }
     for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)    
        result[k++]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    }

}

int main()
{
    int arr[10];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter 10 elements to array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    zeros_to_start(arr,n);
}