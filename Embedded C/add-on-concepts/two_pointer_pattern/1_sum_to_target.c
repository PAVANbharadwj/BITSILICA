#include<stdio.h>
int targetsum(int*arr,int t,int n)
{
    int left=0;
    int right=n-1;
    int sum;
    while(left<right)
    {
        sum=arr[right]+arr[left];
        if(sum == t)
        {
            printf("%d+%d=%d\n",arr[left],arr[right],sum);
        }
        if(sum<t)
        left++;
        else
        right--;
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int t,n;
    n=sizeof(arr)/sizeof(arr[0]);
    printf("enter target sum: ");
    scanf("%d",&t);
    targetsum(arr,t,n);
}