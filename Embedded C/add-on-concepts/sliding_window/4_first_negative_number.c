#include<stdio.h>
void firstnegativewindow(int*ptr,int n,int k)
{
    int arr[10];
    int r=0;
    int found;
    for(int i=0;i<=n-k;i++)
    {   
        found=0;
        for(int j=i;j<i+3;j++)
        {
            if(ptr[j]<0)
            {
                arr[r++]=ptr[j];
                found=1;
                break;
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[]={-2,4,-1,2,-7,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    printf("enter the size of window: ");
    scanf("%d",&k);
    firstnegativewindow(arr,n,k);
}