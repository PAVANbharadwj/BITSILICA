#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    struct Student s1;
    struct Student *ptr = &s1;
    printf("Enter name: ");
    scanf("%s", ptr->name);  
    printf("Enter age: ");
    scanf("%d", &ptr->age);
    printf("Enter marks: ");
    scanf("%f", &ptr->marks);
    printf("\nStudent Info:\n");
    printf("Name  : %s\n", ptr->name);
    printf("Age   : %d\n", ptr->age);
    printf("Marks : %.2f\n", ptr->marks);
    return 0;
}
