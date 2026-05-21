#include<stdio.h>
int main()
{
    double arr[5];
    double*ptr=NULL;
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements to array ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    ptr=arr;
    ptr++;
    ++ptr;
    printf("third element is%d",*ptr);
}