#include <stdio.h>
int main()
{
    int arr[5],n;
    n=sizeof(arr)/sizeof(arr[0]);
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int maxsum = arr[0];
    int currentsum = arr[0];
     for (int i = 1; i < n; i++)
    {
        if (currentsum + arr[i] > arr[i])
            currentsum = currentsum + arr[i];
        else
            currentsum = arr[i];
        if (currentsum > maxsum)
            maxsum = currentsum;
    }
     printf("Maximum contiguous sum is %d\n", maxsum);

}