#include <stdio.h>

void rotate90Clockwise(int mat[][10], int n) {

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

int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    
    int mat[10][10]; 
    printf("Enter elements of %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    rotate90Clockwise(mat, n);

    printf("Matrix after 90-degree clockwise rotation:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}
