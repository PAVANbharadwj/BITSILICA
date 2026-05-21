#include<stdio.h>
int main()
{
    int arr[]={1,1,0,1,1,1,1,0,1,1,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    int maxcount=0,count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            count++;
        }
        else 
        count=0;

        if(count>maxcount)
        {
            maxcount=count;
        }
    }

    printf("maximum number of consiqutive ones are %d",maxcount);
}