#include<stdio.h>
struct stu
{
    unsigned int roll: 4;
    unsigned int marks:4;

};

int main()
{
    struct stu v;
    unsigned int r,s;
    printf("enter name and marks");
    scanf("%lu %lu",&r,&s);
    v.roll=r;
    v.marks=s;
    printf("%d\n%d",v.roll,v.marks);

}