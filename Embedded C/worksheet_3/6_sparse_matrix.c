#include <stdio.h>

int main()
 {
    int rows, cols, countZero = 0, countNonZero = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[20][20];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] == 0)
                countZero++;
            else
                countNonZero++;
        }
    }

    if (countZero > countNonZero)
        printf("\nThe matrix is a SPARSE matrix.\n");
    else
        printf("\nThe matrix is NOT a sparse matrix.\n");

    printf("\nZero elements: %d", countZero);
    printf("\nNon-zero elements: %d\n", countNonZero);


}
