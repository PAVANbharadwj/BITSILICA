#include <stdio.h>

int main()
{
    int n = 12;           
    int rows = 3, cols = 4; 
    int arr1D[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr2D[3][4];

    int k = 0; 
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            arr2D[i][j] = arr1D[k++];
        }
    }

    printf("2D Array:\n");
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            printf("%d ", arr2D[i][j]);
        }
        printf("\n");
    }
}
