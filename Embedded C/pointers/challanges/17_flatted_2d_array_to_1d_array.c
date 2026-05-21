#include <stdio.h>
#define ROWS 3
#define COLS 4
int main()
{
    int array2D[ROWS][COLS] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int k=0;
    int flattened[ROWS * COLS];
        for(int i=0;i<ROWS;i++)
        {
            for(int j=0;j<COLS;j++)
            {
            flattened[k]=array2D[i][j];
            k++;
            }
        }
        printf("flattened array : ");
    for(int i=0;i<k;i++)
    {
        printf("%d ",flattened[i]);
    }
}
