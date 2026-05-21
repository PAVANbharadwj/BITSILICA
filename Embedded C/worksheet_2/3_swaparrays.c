#include<stdio.h>
void swaparrays(int *arr,int *ptr,int n);
void printarray(int*arr,int n);
int main()
{
    int arr[]={1,2,3,4,5};
    int ptr[]={5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    swaparrays(arr,ptr,n);
}
void swaparrays(int *arr,int *ptr,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=ptr[i])
        {
            int temp=arr[i];
            arr[i]=ptr[i];
            ptr[i]=temp;
        }
        
    }
    printarray(arr,n);
    printarray(ptr,n);
}
void printarray(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}