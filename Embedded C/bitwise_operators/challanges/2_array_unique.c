#include <stdio.h>
int main() 
{
    int arr[100], n, result = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        result = result ^ arr[i];
    }
    printf("The unique element is: %d", result);
}

