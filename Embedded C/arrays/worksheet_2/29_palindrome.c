#include<stdio.h>
int main()
{
    int arr[5],temp[5],flag=1;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    for(int i=0;i<size;i++)
    {
        temp[i]=arr[size-i-1];
    }
    for(int i=0;i<size;i++)
    {
        if(temp[i]!=arr[i])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        printf("it is an palindrome");

    }
    else
    printf("not a palindrome");
}