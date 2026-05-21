#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    printf("enter no of variables to store");
    scanf("%d",&a);
    int*ptr=NULL;
    ptr=(int*)calloc(a,sizeof(int));
    printf("enter the values: ");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&ptr[i]);
    }
    for(int i=0;i<a;i++)
    {
        printf("%d ",ptr[i]);
    }
    free(ptr);
    ptr=NULL;
}