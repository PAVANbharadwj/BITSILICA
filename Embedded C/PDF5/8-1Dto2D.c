#include<stdio.h>
int main(){
    int n;
    printf("Enter n value: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int rows,cols;
    printf("enter rows and columns : ");
    scanf("%d%d",&rows,&cols);
    int arr1[rows][cols];
    int index=0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr1[i][j] = arr[index++];
        }
    }
    printf("convert to 2D arrray: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
    return 0;
}