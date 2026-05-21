#include <stdio.h>

int main() 
{
    float A[5][5], AT[5][5], result[5][5];
    int i, j, k;
    int isOrthogonal = 1;

    printf("Enter elements of 5x5 matrix:\n");
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            scanf("%f", &A[i][j]);

    
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            AT[j][i] = A[i][j];

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            result[i][j] = 0;
            for(k = 0; k < 5; k++)
                result[i][j] += A[i][k] * AT[k][j];
        }
    }

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(i == j && result[i][j] != 1)
                isOrthogonal = 0;
            if(i != j && result[i][j] != 0)
                isOrthogonal = 0;
        }
    }

    if(isOrthogonal)
        printf("\nMatrix is ORTHOGONAL\n");
    else
        printf("\nMatrix is NOT orthogonal\n");

    return 0;
}
