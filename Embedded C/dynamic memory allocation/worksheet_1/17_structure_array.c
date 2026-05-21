#include<stdio.h>
#include<stdlib.h>
struct stu
{
    int marks;
};
int main()
{
    int a;
    printf("enter value of a");
    scanf("%d",&a);
    struct stu *ptr=(struct stu*)malloc(a*sizeof(struct stu));
    if(ptr==NULL)
    {
        printf("memory allocation failed");
        exit(0);
    }
    printf("enter data");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&ptr[i].marks);
    }
     for(int i=0;i<a;i++)
    {
        printf("%d ",ptr[i].marks);
    }
    free(ptr);
}