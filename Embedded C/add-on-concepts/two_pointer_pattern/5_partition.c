#include <stdio.h>

void partition(int arr[], int n, int pivot)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        if (arr[left] < pivot)
        {
            left++; 
        }
        else if (arr[right] >= pivot)
        {
            right--; 
        }
        else
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[] = {8, 3, 7, 4, 2, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pivot = 5;

    partition(arr, n, pivot);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
