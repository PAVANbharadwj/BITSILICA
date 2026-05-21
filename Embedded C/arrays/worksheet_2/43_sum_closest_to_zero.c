#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[6],sum,a,b;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    sum=arr[0]+arr[1];
    a=arr[1];
    b=arr[1];
    for (int i = 1; i < size - 1; i++)
    {
        int current_sum = arr[i] + arr[i + 1];
        if (abs(current_sum) < abs(sum))
        {
            sum = current_sum;
            a = arr[i];
            b = arr[i + 1];
        }
    }
    printf("elements sum closest to zero is%d %d",a,b);
}