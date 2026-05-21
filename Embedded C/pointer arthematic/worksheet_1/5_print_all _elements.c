#include<stdio.h>
void printelement(int *ptr,int n);
int main()
{
    int arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements to array ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printelement(arr,n);
}
void printelement(int *ptr,int n)
{
    printf("the elements in the array are: ");
    for(int i=0;i<n;i++)
    {
    printf("%d ",*ptr++);
    }
}
