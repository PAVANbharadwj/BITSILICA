#include<stdio.h>
#include<string.h>
union data
{
    int marks;
    float percent;
    union name{
        char name[20];
    }v;
}u;
int main()
{
 u.marks=100;
 printf("%d\n",u.marks);
 u.percent=90.5;
 printf("%f\n",u.percent);
 strcpy(u.v.name,"bobby");
 printf("%s",u.v.name);
 printf("size of union:%d",sizeof(union data));
}