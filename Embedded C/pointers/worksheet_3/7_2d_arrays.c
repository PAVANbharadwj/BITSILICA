#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int rows = 4, cols = 4;
    int **reg_block;
    reg_block = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        reg_block[i] = malloc(cols * sizeof(int));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            reg_block[i][j] = i * cols + j;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%3d ", reg_block[i][j]);
        printf("\n");
    }
    for (int i = 0; i < rows; i++)
    free(reg_block[i]);
    free(reg_block);
}
