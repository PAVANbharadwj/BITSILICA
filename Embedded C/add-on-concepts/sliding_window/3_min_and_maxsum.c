#include<stdio.h>
void findsum(int*ptr,int n,int k)
{
    int currentsum=0,maxsum=0,minsum=0;
    
    for(int i=0;i<k;i++)
    currentsum += ptr[i];
    
    maxsum=currentsum;
    minsum=currentsum;

    for(int i=k;i<n;i++)
    {
        currentsum += ptr[i] - ptr[i-k];
        
        if(currentsum>maxsum)
            maxsum=currentsum;
        else if(currentsum<minsum)
            minsum=currentsum;
    }
    printf("maxsum=%d\nminsum=%d",maxsum,minsum);
}
int main()
{
    int arr[]={2,1,5,1,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    printf("enter the value of k: ");
    scanf("%d",&k);
    findsum(arr,n,k);
}