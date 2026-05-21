#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    int*ptr=NULL;
    ptr=malloc(3*sizeof(int));
    if(ptr==NULL)
    {
        printf("memory allocation failed");
        exit(0);
    }
    ptr[0]=100;
    ptr[1]=200;
    ptr[2]=300;
    for(int i=0;i<3;i++)
    printf("%d ",ptr[i]);
    ptr=realloc(ptr,2*sizeof(int));
    printf("\n%d\n",sizeof(ptr));
    for(int i=0;i<2;i++)
    printf("%d ",ptr[i]);
    free(ptr);

}