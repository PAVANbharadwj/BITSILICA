#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    struct Student *stu = (struct Student *)malloc(sizeof(struct Student));
    if (stu == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    strcpy(stu->name, "Hemu");
    stu->age = 21;
    stu->marks = 88.5;
    printf("Name  : %s\n", stu->name);
    printf("Age   : %d\n", stu->age);
    printf("Marks : %.2f\n", stu->marks);
    free(stu);
    return 0;
}
