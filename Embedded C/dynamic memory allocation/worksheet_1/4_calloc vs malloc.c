#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    printf("enter no of variables to store");
    scanf("%d",&a);
    int*ptr=NULL;
    ptr=(int*)calloc(a,sizeof(int));
    int*ptr1=(int*)malloc(a*sizeof(int));
    printf("calloc values: ");
    for(int i=0;i<a;i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\nmalloc values: ");
    for(int i=0;i<a;i++)
    {
        printf("%d ",ptr1[i]);
    }
    free(ptr);
    free(ptr1);
    ptr=NULL;
}