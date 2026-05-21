#include<stdio.h>
struct stu{
    char name[8];
    int marks;
};
union tu{
    char name[8];
    int marks;
};
int main()
{
    printf("size of structure: %d\n",sizeof(struct stu));
    printf("size of union: %d",sizeof(union tu));
}