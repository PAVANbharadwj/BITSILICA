#include<stdio.h>

int main()
{
    int arr[]={2,7,3,5,1,3,9};
    int k,size,maxsum=0,currentsum=0;
    
    printf("enter the value of group");
    scanf("%d",&k);
    size=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<k;i++)
    currentsum +=arr[i];
    
    maxsum=currentsum;

    for(int i=k;i<size;i++)
    {
        currentsum += arr[i]-arr[i-k];
        if(currentsum>maxsum)
        {
            maxsum=currentsum;
        }
    }
    printf("the max sum is: %d",maxsum);
}