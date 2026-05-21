#include<stdio.h>
int main()
{
    int arr[5];
    int n,count=0;
    n=5;
    printf("enter the elements intoi array");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
    if(arr[i]<0)
    count++;
    }
    printf("Total negative integers are%d",count);

}