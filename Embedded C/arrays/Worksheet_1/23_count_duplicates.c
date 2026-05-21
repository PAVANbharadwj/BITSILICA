#include <stdio.h>
#include <string.h> 
int countDuplicates(int *arr, int n)
{
   int count;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[100], n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    n = countDuplicates(arr, n);
    printf("duplicates count is %d",n);
}