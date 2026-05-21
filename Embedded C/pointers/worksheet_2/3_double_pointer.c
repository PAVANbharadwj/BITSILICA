#include<stdio.h>
#include<stdlib.h>
void modifymemory(int**ptr);
int main()
{
    int num=10;
    int*ptr=&num;
    int**pptr=&ptr;
    printf("%d",**pptr);
    modifymemory(pptr);
}
void modifymemory(int**ptr)
{
*ptr=(int*)malloc(2*sizeof(int));
if(*ptr==NULL)
{
    printf("memory allocation failed");
}
(*ptr)[0]=100;
(*ptr)[1]=200;
printf("\n%d %d",(*ptr)[0],(*ptr)[1]);
free(*ptr);
}
