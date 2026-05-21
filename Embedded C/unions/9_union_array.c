#include<stdio.h>
#include<stdlib.h>
union name
{
    int marks;
}v;
int main()
{
    union name*p=malloc(2*sizeof(union name));
    if(!p)
    {
        printf("memory allocation failed");
        return 0;
    }
    for(int i=0;i<2;i++)
    {
        scanf("%d",&p[i].marks);
    }
     for(int i=0;i<2;i++)
    {
        printf("%d\n",p[i].marks);
    }
    free(p);

}