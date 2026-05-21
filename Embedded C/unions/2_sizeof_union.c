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
    printf("size of union:%d\n",sizeof(union data));
}