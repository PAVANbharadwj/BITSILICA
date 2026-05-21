#include <stdio.h>

void printSubset(int arr[], int n, int index, int subset[], int subSize) 
{
    if (index == n) 
    {
        if (subSize == 0)
            printf("{}");
        else
            for (int i = 0; i < subSize; i++)
                printf("%d ", subset[i]);

        printf("\n");
        return;
    }

    printSubset(arr, n, index + 1, subset, subSize);

    subset[subSize] = arr[index];
    printSubset(arr, n, index + 1, subset, subSize + 1);
}

int main() 
{
    int arr[] = {1, 2, 3};
    int subset[10];
    int n = 3;

    printSubset(arr, n, 0, subset, 0);

    return 0;
}
