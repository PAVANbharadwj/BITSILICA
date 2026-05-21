#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b;
    printf("enter no of rows and columns\n");
    scanf("%d%d",&a,&b);
    int size=a*b;
    int*ptr=(int*)malloc(size*sizeof(int));
    printf("enter values to matrix: ");
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            scanf("%d",&ptr[i*b+j]);
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            printf("%d ",ptr[i*b+j]);
        }
    }
}