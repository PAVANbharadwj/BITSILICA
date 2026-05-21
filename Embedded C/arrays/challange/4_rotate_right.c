#include <stdio.h>
int main()
{
    int arr[5], n, temp;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter elements to array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter how many times to rotate: ");
    scanf("%d", &n);
    n = n % size;
    for (int i = 0; i < n; i++)
    {
        temp = arr[size - 1]; 
        for (int j = size - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    printf("Array after right rotation:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}