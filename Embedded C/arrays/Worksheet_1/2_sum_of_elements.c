#include<stdio.h>
int main()
{
    int arr[5];
    int sum=0,size;
    size=sizeof(arr)/sizeof(arr[0]);
    printf("enter the elements into array");
    for(int i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
    for(int i=0;i<size;i++)
    {
        sum=sum+arr[i];
    }
printf("The sum of elements in the array are:%d",sum);
}