#include<stdio.h>
void printelement(int *ptr);
int main()
{
    int arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements to array ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printelement(arr);
}
void printelement(int *ptr)
{
    ptr++;
    ++ptr;
    printf("the element is %d",*ptr);
}