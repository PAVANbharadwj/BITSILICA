#include<stdio.h>
int main()
{
    int arr[5],count=0,majority=-1;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
     {
        scanf("%d",&arr[i]);
     }
    for(int i=0;i<size;i++)
    {
        count=0;
    for(int j=0;j<size;j++)
    if(arr[i]==arr[j])
    {
        count++;
    }
    if(count > size/2)
    {
        majority=arr[i];
        break;
    }
    }
  if(majority!=-1)
    printf("majority element is%d",majority);

}