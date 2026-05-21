#include <stdio.h>
#include <string.h> 
int removeDuplicates(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
    for (int j = i + 1; j < n; j++)
    {
    if (arr[i] == arr[j])
    {
    memmove(arr+j, arr+j + 1, (n - j - 1) * sizeof(int));
     n--;  
    j--;
    }
     }
    }
    return n;
}

int main()
{
    int arr[100], n;

    printf("Enter size of array: ");
    scanf("%d", &n);
     printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    n = removeDuplicates(arr, n);
    printf("\nArray after removing duplicates:\n");
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

    return 0;
}
