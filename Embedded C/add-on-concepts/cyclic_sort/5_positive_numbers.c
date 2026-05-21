#include <stdio.h>
int firstMissingPositive(int arr[], int n) 
{
    int i = 0;
    while (i < n) 
    {
        int correct = arr[i] - 1;
        if (arr[i] > 0 && arr[i] <= n && arr[i] != arr[correct]) 
        {
            int temp = arr[i];
            arr[i] = arr[correct];
            arr[correct] = temp;
        }
         else 
        {
            i++;
        }
    }

    for (i = 0; i < n; i++) 
    {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

int main() 
{
    int arr[] = {3,4,-1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("First Missing Positive = %d\n", firstMissingPositive(arr, n));
}