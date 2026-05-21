#include <stdio.h>
void transpose(int rows, int cols, int ptr[rows][cols]);
int main() {
    int arr[3][2];
    printf("enter the elements to matrix\n");
    for(int i=0; i<3; i++) 
    {
        for(int j=0; j<2; j++)
            scanf("%d", &arr[i][j]);
    }
    printf("Before transpose:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<2; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

transpose(3, 2, arr);
}

void transpose(int rows, int cols, int ptr[rows][cols]) {
    int prr[cols][rows]; 
  
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            prr[j][i] = ptr[i][j];
        }
    }
    printf("After transpose:\n");
    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++)
            printf("%d ", prr[i][j]);
        printf("\n");
    }
}
