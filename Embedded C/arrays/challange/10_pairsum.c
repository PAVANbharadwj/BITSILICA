#include<stdio.h>
int main()
{
    int arr[6],sum,count=0;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("enter sum\n");
    scanf("%d",&sum);
    for(int i=0;i<size;i++)
    {
        if((arr[i]+arr[i+1])==sum)
        {
            count++;
        }

    }
    printf("pair count matching to sum is %d",count);
}