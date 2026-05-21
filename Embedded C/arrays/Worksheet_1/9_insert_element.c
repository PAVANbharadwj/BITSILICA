#include<stdio.h>
int main()
{
    int arr[5],num,pos;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements into array\n");
    for(int i=0;i<size-1;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("enter the element you want to insert");
    scanf("%d",&num);
    printf("enter the position");
    scanf("%d",&pos);
    for(int i=size-1;i>=pos;i--)
    {
    arr[i+1]=arr[i];
    }
    arr[pos]=num;
    for(int i=0;i<size;i++)
    {
    printf("%d ",arr[i]);
    }
}