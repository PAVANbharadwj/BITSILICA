#include<stdio.h>
void sort(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("after sorting: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}


int main()
{
    int arr[]={5,3,7,1,2,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,n);
}