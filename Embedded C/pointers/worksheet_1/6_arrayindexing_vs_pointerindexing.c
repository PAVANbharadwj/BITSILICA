#include<stdio.h>
void pointerindexing(int *ptr,int n);
void arrayindexing(int *ptr,int n);
int main()
{
    int arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements to array ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    pointerindexing(arr,n);
    arrayindexing(arr,n);
}
void pointerindexing(int *ptr,int n)
{
    printf("the elements in the array are: ");
    for(int i=0;i<n;i++)
    {
    printf("%d ",*(ptr+i));
    }
}
void arrayindexing(int *ptr,int n)
{
    printf("\nthe elements in the array are: ");
    for(int i=0;i<n;i++)
    {
    printf("%d ",ptr[i]);
    }
}