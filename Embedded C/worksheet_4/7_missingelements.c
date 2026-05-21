#include<stdio.h>
void missing_elements(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("the missing elementys are: ");
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        if(arr[j]!=arr[i]+1)
        {
            printf("%d",arr[i]+1);
        }
    }
}

int main()
{
    int arr[6];
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("enter elements to array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d ",&arr[i]);
    }
    missing_elements(arr,n);
}