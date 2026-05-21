#include<stdio.h>
int main()
{
 int arr[5],arr1[3],flag=0;
    int size=sizeof(arr)/sizeof(arr[0]);
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("enter elements to array\n");
    for(int i=0;i<size1;i++)
    {
    scanf("%d",&arr1[i]);
    }
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size;j++)
        {
        if(arr[i]==arr[j])
        {
            flag=1;
        }
    }
}
    if(flag==1)
    {
    printf("2is subarray of 1");
    }
}