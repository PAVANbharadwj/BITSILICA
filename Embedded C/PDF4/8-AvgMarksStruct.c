#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    int n;
    float sum = 0, avg;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);  // reads string with spaces
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        sum += students[i].marks;
    }
    avg = sum / n;
    printf("\nAverage Marks = %.2f\n", avg);
    return 0;
}
