#include<stdio.h>
struct stu
{
    char name[10];
    int roll;
    float marks;
};
int main()
{
    struct stu s1={"roy",10,9.5};
    struct stu *ptr=&s1;
    printf("name: %s\n",ptr->name);
    printf("roll: %d\n",ptr->roll);
    ptr->marks=99;
    printf("marks: %f\n",ptr->marks);

}