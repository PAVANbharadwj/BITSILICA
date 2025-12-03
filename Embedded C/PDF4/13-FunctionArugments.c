#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void display(struct Student s) {
    printf("Roll No: %d\n", s.rollNo);
    printf("Name   : %s\n", s.name);
    printf("Marks  : %.2f\n", s.marks);
}

struct Student inputStudent() {
    struct Student s;
    printf("Enter roll number: ");
    scanf("%d", &s.rollNo);
    printf("Enter name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    return s;
}

int main() {
    struct Student s1 = inputStudent();
    printf("\nStudent Details:\n");
    display(s1);

    return 0;
}
