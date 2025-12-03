#include <stdio.h>

int main() {
    int m, p, n;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &m, &p);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &p, &n);

    int A[m][p], B[p][n], C[m][n];

    printf("Enter elements to matrix A: ");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < p; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements to Matrix B: ");
    for(int i = 0; i < p; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Resultant Matrix C:\n", m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
