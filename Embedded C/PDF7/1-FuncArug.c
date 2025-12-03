#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

struct Person per(struct Person p) {
    p.age += 1;
    strcat(p.name," pooji");
    return p;
}

int main() {
    struct Person p1;
    printf("Enter name: ");
    scanf("%s", p1.name);
    printf("Enter age: ");
    scanf("%d", &p1.age);
    struct Person updated = per(p1);
    printf("Updated Name: %s\n", updated.name);
    printf("Updated Age: %d\n", updated.age);
    return 0;
}
