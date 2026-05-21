#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    int*ptr;
    int count=0;
    printf("enter value of a");
    scanf("%d",&a);
    ptr=(int*)calloc(a,sizeof(int));
    for(int i=0;i<a;i++)
    {
        scanf("%d",&ptr[i]);
    }
    for(int i=0;i<a;i++)
    {
        if(ptr[i]==0)
        continue;
        count=1;
        for(int j=i+1;j<a;j++)
        {
            if(ptr[i]==ptr[j] && ptr[i]!='*')
            count++;
            ptr[j]=0;
        }
        printf("The element %d count is %d\n",ptr[i],count);
    }
    free(ptr);
}