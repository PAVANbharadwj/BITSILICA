#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student getStudent() {
    struct Student s;
    printf("Enter student roll: ");
    scanf("%d", &s.roll);
    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter student marks: ");
    scanf("%f", &s.marks);
    return s; 
}
void displayStudent(struct Student s) {
    printf("Roll: %d\n", s.roll);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);
}

int main() {
    struct Student s1 = getStudent();
    displayStudent(s1);
    return 0;
}
