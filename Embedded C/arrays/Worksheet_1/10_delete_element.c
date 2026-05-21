#include<stdio.h>
int main()
{
    int arr[5],pos;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements into array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("enter the delete position");
    scanf("%d",&pos);
    for(int i=pos;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}