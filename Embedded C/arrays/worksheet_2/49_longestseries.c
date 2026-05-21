#include <stdio.h>

int main()
{
    int arr[8], i, j, temp;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < size - 1; i++)
    {
    for (j = i + 1; j < size; j++)
    {
    if (arr[i] > arr[j])
    {
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    }
       }
    }
    int count = 1, max = 1;
    for (i = 1; i < size; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            count++;
            if (count > max)
                max = count;
        }
        else if (arr[i] != arr[i - 1])
        {
            count = 1;
        }
    }
printf("Longest consecutive series length: %d\n", max);
}
