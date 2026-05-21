#include <stdio.h>
#include <string.h>
void removeDuplicates(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
            printf("%d ",arr[i]);
            break;
            }
        }
    }
}

int main()
{
    int arr[100], n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    removeDuplicates(arr, n);
}
