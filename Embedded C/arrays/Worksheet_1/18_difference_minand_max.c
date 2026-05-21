#include<stdio.h>
int main()
{
    int arr[5],min,max;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    if(arr[0]>arr[1])
    {
        max=arr[0];
        min=arr[1];
    }
    for(int i=2;i<size;i++)
    {
      if(arr[i]>max)
      {
        min=max;
        max=arr[i];
      }
      else if(arr[i]<min)
      {
        min=arr[i];
      }
    }
    printf("difference=%d",max-min);

}