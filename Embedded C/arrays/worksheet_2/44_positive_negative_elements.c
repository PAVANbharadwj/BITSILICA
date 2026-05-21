#include <stdio.h>
int main()
{
    int arr[6];
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter %d elements:\n", size);
        for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
        printf("Array after alternate arrangement:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] >= 0 && arr[j] < 0)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                break;
            }
        }
    }

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}

