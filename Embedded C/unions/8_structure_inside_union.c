#include<stdio.h>
union name
{
    int rollno;
    struct marks
    {
        int marks;
        char grade;
    }u;
}v;

int main()
{
    printf("%d",sizeof(union name));
    v.u.marks=100;
    v.u.grade='A';
    printf("\nmarks: %d\ngrade: %c",v.u.marks,v.u.grade);
    
}