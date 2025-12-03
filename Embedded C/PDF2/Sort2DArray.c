#include<stdio.h>
int main(){
    int row,col;
    printf("Enter rows and col size: ");
    scanf("%d%d",&row,&col);
    int arr[row][col];
    printf("Enter elements into array: ");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i1=0;i1<row;i1++){
        for(int j1=0;j1<col;j1++){
            for(int i2=0;i2<row;i2++){
                for(int j2=0;j2<col;j2++){
                    if(arr[i1][j1]<arr[i2][j2]){
                        int temp=arr[i1][j1];
                        arr[i1][j1]=arr[i2][j2];
                        arr[i2][j2]=temp;
                    }
                }
            }
        }
    }
    printf("Sorted 2D array: \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}