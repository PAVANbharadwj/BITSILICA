#include<stdio.h>
#include<string.h>
union data{
    int num;
    float marks;
    char name[20];
};
int main()
{
    union data v={100,22.5,"bobby"};
    printf("%d\n",v.num);
    printf("%f\n",v.marks);
    printf("%s",v.name);
}