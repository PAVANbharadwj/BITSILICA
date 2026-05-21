#include<stdio.h>
int main(){
    int rows,cols;
    printf("Enter rows and columns : ");
    scanf("%d%d",&rows,&cols);
    int matrix[rows][cols];
    printf("Enter elements into matrix: ");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Boundary elements in matrix: ");
    for(int j=0;j<cols;j++){
        printf("%d ",matrix[0][j]);
    }
    for(int i=1;i<rows;i++){
        printf("%d ",matrix[i][cols-1]);
    }
    if(rows>1){
        for(int j=cols-2;j>=0;j--){
            printf("%d ",matrix[rows-1][j]);
        }
    }
    if(cols>1){
        for(int i=rows-2;i>0;i--){
            printf("%d ",matrix[i][0]);
        }
    }
    return 0;
}