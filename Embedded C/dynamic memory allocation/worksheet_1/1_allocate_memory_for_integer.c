#include<stdio.h>
#include<stdlib.h>
int main()
{
    int*ptr;
    ptr=(int*)malloc(1*sizeof(int));
    printf("enter the value");
    scanf("%d",ptr);
    printf("%d",*ptr);
    free(ptr);
    ptr=NULL;
}