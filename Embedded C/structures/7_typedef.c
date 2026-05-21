#include<stdio.h>
typedef struct stu{
    int marks;
    char grade;
}student;
int main()
{
    student v;
    printf("enter marks and grade: ");
    scanf("%d %c",&v.marks,&v.grade);
    printf("marks: %d\ngrade: %c",v.marks,v.grade);
}