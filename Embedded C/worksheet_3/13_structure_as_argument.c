#include <stdio.h>

struct Student
{
    char name[20];
    int age;
};


void display(struct Student s)
 {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", s.name);
    printf("Age : %d\n", s.age);
}

int main()
{
    struct Student s1;

    printf("Enter name: ");
    scanf("%s", s1.name);

    printf("Enter age: ");
    scanf("%d", &s1.age);


    display(s1);

    return 0;
}
