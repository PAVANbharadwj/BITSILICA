#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    printf("enter no of variables to store");
    scanf("%d",&a);
    int*ptr=NULL;
    ptr=(int*)malloc(a*sizeof(int));
    printf("enter values");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("\nbefore insert");
    for(int i=0;i<a;i++)
    {
        printf("%d ",ptr[i]);
    }
    a=a+1;
    ptr=realloc(ptr,a*sizeof(int));
    int b;
    printf("\nenter location whete to insert");
    scanf("%d",&b);
    for(int i=a-1;i>=b;i--)
    {
        ptr[i+1]=ptr[i];
    }
    printf("\nenter number to insert");
    scanf("%d",&ptr[b]);
    printf("\nafter insert");
    for(int i=0;i<a;i++)
    {
        printf("%d ",ptr[i]);
    }
    free(ptr);

}