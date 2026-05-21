#include<stdio.h>
void nonrepeating(int *ptr,int n)
{
    int result=0;
    for(int i=0;i<n;i++)
    {
        result=result^ptr[i];
    }
    printf("The non repeating element in array is %d",result);
}

int main()
{
    int arr[]={1,2,5,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    nonrepeating(arr,n);
}