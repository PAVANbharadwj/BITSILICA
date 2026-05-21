#include<stdio.h>
int main()
{
    int arr[]={1,2,3,4,0,9,10,11,12,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    int maxcount=1,count=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i+1]>arr[i])
        {
            count++;
        }
        else 
        count=1;

        if(count>maxcount)
        {
            maxcount=count;
        }
    }

    printf("strictly increasing order %d",maxcount);
}