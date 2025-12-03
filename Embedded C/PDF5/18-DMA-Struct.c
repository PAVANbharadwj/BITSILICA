#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student *s = (struct Student *)malloc(sizeof(struct Student));
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    s->roll = 101;
    sprintf(s->name, "Hemanth");
    s->marks = 85.5;
    printf("Roll: %d\nName: %s\nMarks: %.2f\n", s->roll, s->name, s->marks);
    free(s);
    return 0;
}