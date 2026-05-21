#include<stdio.h>
void reversearray(int *ptr,int n);
int main()
{
    int arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements to array ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    reversearray(arr,n);
}
void reversearray(int *ptr,int n)
{
    int*start=ptr;
    int*end=ptr+n-1;
    int temp;
    while(start<end)
    {
        temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
    printf("reversed elements are : ");
    for(int i=0;i<n;i++)
    printf("%d ",ptr[i]);
}