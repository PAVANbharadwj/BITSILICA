#include <stdio.h>

int main()
{
    int arr[100], n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nOccurrences of all elements:\n");
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        if (arr[i] == -1) 
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                arr[j] = -1; 
            }
        }
    printf("%d occurs %d times\n", arr[i], count);
    }
}
