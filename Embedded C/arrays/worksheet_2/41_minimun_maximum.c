#include<stdio.h>
int main()
{
 int arr[5],max,small;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    if(arr[0]>arr[1])
    {
        max=arr[0];
        small=arr[1];
    }
    else
    {
        max=arr[1];
        small=arr[0];
        
    }
     for(int i=2;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    else if(arr[i]<small && arr[i]!=max)
    {
        small=arr[i];
    }
}

printf("max:%d\nminimum:%d\n",max,small);
}