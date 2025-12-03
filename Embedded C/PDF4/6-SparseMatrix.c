#include<stdio.h>
int main(){
    int rows,cols;
    printf("Enter rows and columns: ");
    scanf("%d%d",&rows,&cols);
    int arr[rows][cols];
    int count=0;
    printf("Enter array elements: ");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0){
                count++;
            }
        }
    }
    int totalCount=rows*cols;
    if(count>(totalCount/2)){
        printf("The given matrix is parse matrix");
    }
    else{
        printf("The matrix is not parse matrix");
    }
    return 0;
}