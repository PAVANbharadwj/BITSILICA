#include <stdio.h>
#include <string.h>

// Define structure
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Function that uses pointer to structure
void updateMarks(struct Student *s, float newMarks) {
    s->marks = newMarks;  // Use -> to access members via pointer
}

void display(struct Student *s) {
    printf("Roll No: %d\n", s->rollNo);
    printf("Name   : %s\n", s->name);
    printf("Marks  : %.2f\n", s->marks);
}

int main() {
    struct Student s1;
    printf("Enter roll number: ");
    scanf("%d", &s1.rollNo);
    printf("Enter name: ");
    scanf(" %[^\n]", s1.name);
    printf("Enter marks: ");
    scanf("%f", &s1.marks);
    printf("\nBefore Update:\n");
    display(&s1);
    updateMarks(&s1, 95.5);
    printf("\nAfter Update:\n");
    display(&s1);

    return 0;
}
