#include<stdio.h>
#pragma pack(1)
struct stu{
    int marks;
    float roll;
    char grade;
    double total;

};

int main()
{
    printf("sizeof structure is %d",sizeof(struct stu));
}