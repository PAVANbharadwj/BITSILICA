#include<stdio.h>
void printarray(int*arr,int n);
int main()
{
    int arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements to array ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printarray(arr,n);
}
void printarray(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i]+1;
        printf("%d ",arr[i]);
    }
}