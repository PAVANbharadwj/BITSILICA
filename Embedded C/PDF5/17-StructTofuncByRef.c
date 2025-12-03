#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};
void updateStudent(struct Student *s) {
    s->roll = 1001;
    sprintf(s->name, "Hemanth");
    s->marks = 92.5;
}

void displayStudent(const struct Student *s) {
    printf("Roll: %d\n", s->roll);
    printf("Name: %s\n", s->name);
    printf("Marks: %.2f\n", s->marks);
}

int main() {
    struct Student s1 = {0, "", 0.0};
    updateStudent(&s1);
    displayStudent(&s1);
    return 0;
}
