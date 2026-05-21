#include<stdio.h>
#define n 3
void rotatematrix(int arr[n][n])
{
    //transpose matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    //rotate matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0,k=n-1;j<k;j++,k--)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[k][j];
            arr[k][j]=temp;

        }
    }
    //print matrix
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[n][n];
    printf("enter elements to matrix: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    rotatematrix(arr);
}