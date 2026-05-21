#include <stdio.h>

struct Student
{
    char name[20];
    int age;
};

int main()
{
    struct Student s1, *ptr;

    ptr = &s1; 

    printf("Enter name: ");
    scanf("%s", ptr->name);   

    printf("Enter age: ");
    scanf("%d", &ptr->age);

    printf("\nStudent Details:\n");
    printf("Name: %s\n", ptr->name);
    printf("Age : %d\n", ptr->age);

}
