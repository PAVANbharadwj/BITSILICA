#include <stdio.h>

int isSymmetric(int matrix[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i])
                return 0;  
        }
    }
    return 1;  
}

int main() {
    int n;
    printf("Enter size of square matrix (max 10): ");
    scanf("%d", &n);

    int matrix[10][10];
    printf("Enter matrix elements (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    if (isSymmetric(matrix, n))
        printf("Matrix is symmetric.\n");
    else
        printf("Matrix is not symmetric.\n");

    return 0;
}
