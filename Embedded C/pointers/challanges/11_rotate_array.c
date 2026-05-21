#include <stdio.h>
void rotate(int *arr, int n, int k)
{
    k = k % n;
    for (int i = 0; i < k; i++)
    {
        int last = arr[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            *(arr + j) = *(arr + j - 1);
        }
        *arr = last;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    rotate(arr, n, k);
    printf("Rotated array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}
