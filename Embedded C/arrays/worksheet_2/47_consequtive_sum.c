#include <stdio.h>
int main()
{
    int arr[6];
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter %d elements:\n", size);
   for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
     int max_sum = arr[0];
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum = sum + arr[j];
            if (sum > max_sum)
                max_sum = sum;
        }
    }

    printf("Maximum sum of consecutive elements: %d\n", max_sum);
}
