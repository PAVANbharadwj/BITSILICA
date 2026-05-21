#include <stdio.h>
int main()
{
    int arr[5],n;
    n=sizeof(arr)/sizeof(arr[0]);
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    int leader=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        {
            leader=arr[i];
            printf("%d ",leader);
        }
    }

}