#include<stdio.h>
int main()
{
    int arr[5],sum=0;
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array\n");
    for(int i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
for(int i=0;i<size;i++)
{
    if(arr[i]%2==0)
    {
        sum+=arr[i];
    }

}
printf("sum of evev numbers is %d",sum);

}