#include <stdio.h>

void cyclicSort(int arr[], int n) 
{
    int i = 0;
    while (i < n) 
    {
        int correctIndex = arr[i] - 1;
        if (arr[i] != arr[correctIndex]) 
        {
            int temp = arr[i];
            arr[i] = arr[correctIndex];
            arr[correctIndex] = temp;
        } 
        else
        {
            i++;
        }
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() 
{
    int arr[] = {3, 5, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cyclicSort(arr, n);
    printArray(arr, n);

    return 0;
}
