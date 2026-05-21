#include<stdio.h>
void printarray(int rows,int cols,int arr[rows][cols]);
int main()
{
    int arr[3][3];
    printf("enter elements to array\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printarray(3,3,arr);
}

void printarray(int rows,int cols,int arr[rows][cols])
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}