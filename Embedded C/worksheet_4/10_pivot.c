#include <stdio.h>

int main() 
{
    int arr[] = {1, 7, 3, 6, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int total = 0;


    for(int i = 0; i < n; i++)
        total += arr[i];

    int leftSum = 0;

    for(int i = 0; i < n; i++) 
    {
        if(leftSum == total - leftSum - arr[i])
        {
            printf("Pivot index is %d\n", i);
            return 0;
        }
        leftSum += arr[i];
    }

    printf("No pivot index found\n");
    return 0;
}
