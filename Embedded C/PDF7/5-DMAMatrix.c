#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, max;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int *matrix = (int *)malloc(n * n * sizeof(int));
    if (!matrix) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n * n; i++)
        scanf("%d", &matrix[i]);

    int sum = 0;
    max = matrix[0];
    for (int i = 0; i < n; i++) {
        sum += matrix[i * n + i];             
        sum += matrix[i * n + (n - i - 1)];   
    }

    for (int i = 0; i < n * n; i++)
        if (matrix[i] > max)
            max = matrix[i];

    printf("Sum of diagonals: %d\n", sum);
    printf("Maximum element: %d\n", max);

    free(matrix);
    return 0;
}
