#include <stdio.h>
#define n 3

void transpose(int arr[n][n]) 
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++) 
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

void printMatrix(int arr[n][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[n][n];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    printf("\nOriginal Matrix:\n");
    printMatrix(arr);

    transpose(arr);

    printf("\nTransposed Matrix:\n");
    printMatrix(arr);

    return 0;
}
