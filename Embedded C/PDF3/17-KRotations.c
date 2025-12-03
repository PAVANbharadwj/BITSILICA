#include <stdio.h>
void rotate90(int mat[][10], int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][k];
            mat[i][k] = temp;
        }
    }
}

void printMatrix(int mat[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, k;
    printf("Enter the size of square matrix: ");
    scanf("%d", &n);

    int mat[10][10];
    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    printf("Enter number of 90 clockwise rotations: ");
    scanf("%d", &k);
    k = k % 4;

    for (int i = 0; i < k; i++) {
        rotate90(mat, n);
    }

    printf("Matrix after %d rotation(s):\n", k);
    printMatrix(mat, n);

    return 0;
}
