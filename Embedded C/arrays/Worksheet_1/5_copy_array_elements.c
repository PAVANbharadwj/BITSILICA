#include<stdio.h>
int main()
{
    int arr[5]={1,2,3,4,5},arr1[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        arr1[i]=arr[i];
    }
    printf("copied array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);
    }



}