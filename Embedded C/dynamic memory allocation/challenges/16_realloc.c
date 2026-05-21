#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    printf("enter no of variables to store");
    scanf("%d",&a);
    int*ptr=NULL;
    ptr=(int*)malloc(a*sizeof(int));
    printf("enter the values: ");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&ptr[i]);
    }
    for(int i=0;i<a;i++)
    {
        printf("%d ",ptr[i]);
    }
    ptr=(int*)realloc(ptr,4*sizeof(int));
    printf("after re allocation: ");
    for(int i=0;i<a;i++)
    {
        printf("%d ",ptr[i]);
    }
    free(ptr);
    ptr=NULL;
}