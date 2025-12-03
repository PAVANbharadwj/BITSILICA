#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student *students[n];
    for (int i = 0; i < n; i++) {
        students[i] = (struct Student *)malloc(sizeof(struct Student));
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll: ");
        scanf("%d", &students[i]->roll);
        printf("Name: ");
        scanf(" %[^\n]", students[i]->name);
        printf("Marks: ");
        scanf("%f", &students[i]->marks);
    }
    for (int i = 0; i < n; i++) {
        printf("Student %d: Roll = %d, Name = %s, Marks = %.2f\n",
               i + 1, students[i]->roll, students[i]->name, students[i]->marks);
    }
    for (int i = 0; i < n; i++) {
        free(students[i]);
    }

    return 0;
}
