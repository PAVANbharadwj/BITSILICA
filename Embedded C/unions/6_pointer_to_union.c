#include<stdio.h>
#include<stdlib.h>
union stu{
    int marks;
    char name[20];
};
int main()
{
    union stu*p=malloc(2*sizeof(union stu));
    if(!p)
    {
        printf("memory allocation failed");
        return 0;
    }
    p->marks=10;
    printf("%d\n",p->marks);
    p[1]=p[0];
    for(int i=0;i<2;i++)
    {
    printf("%d\n",p[i].marks);
    }
    free(p);
}
