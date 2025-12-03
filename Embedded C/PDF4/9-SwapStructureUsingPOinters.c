#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void swapStructs(struct Student *s1, struct Student *s2) {
    struct Student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main() {
    struct Student A = {101, "Rahul", 85.5};
    struct Student B = {102, "Priya", 92.0};

    printf("Before Swapping:\n");
    printf("Student A: %d, %s, %.2f\n", A.rollNo, A.name, A.marks);
    printf("Student B: %d, %s, %.2f\n", B.rollNo, B.name, B.marks);

    swapStructs(&A, &B);

    printf("\nAfter Swapping:\n");
    printf("Student A: %d, %s, %.2f\n", A.rollNo, A.name, A.marks);
    printf("Student B: %d, %s, %.2f\n", B.rollNo, B.name, B.marks);

    return 0;
}
