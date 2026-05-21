#include<stdio.h>
void reversearray(int*ptr,int n)
{
    int right=n-1,left=0;
    while(left<right)
    {
        if(ptr[right] != ptr[left])
        {
            int temp=ptr[right];
            ptr[right]=ptr[left];
            ptr[left]=temp;
        }

    left++;
    right--;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
}

int main()
{
    int arr[]={1,2,3,4,1,0,9,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    reversearray(arr,n);
}