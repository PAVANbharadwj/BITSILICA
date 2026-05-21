#include<stdio.h>
int main()
{
int arr[5];
int size,min,max;
 for(int i=0;i<size;i++)
    {
            scanf("%d",&arr[i]);
    }
 size=sizeof(arr)/sizeof(arr[0]);
        min=arr[0];
        max=arr[0];
for(int i=1;i<size;i++)
{
    if(min>arr[i])
    {
        min=arr[i];
    }
    if(max<arr[i])
    {
        max=arr[i];
    }
}
printf("minimum:%d\nmaximum:%d\n",min,max);
}