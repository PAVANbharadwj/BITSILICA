#include<stdio.h>
#include<string.h>
union data{
    int num;
    float marks;
    char name[20];
};
int main()
{
    union data v;
    printf("size of:%d\n",sizeof(union data));
    v.num=100;
    printf("%d\n",v.num);
    v.marks=22.9;
    printf("%f\n",v.marks);
    strcpy(v.name,"bobby");
    printf("%s",v.name);
}