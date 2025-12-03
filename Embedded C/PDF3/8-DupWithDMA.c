#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* duplicate(const char *str) {
    char *copy = (char *)malloc(strlen(str) + 1);
    if (copy == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(copy, str);
    return copy;
}

int main() {
    char original[] = "HelloWorld";
    char *p = duplicate(original);
    if (p != NULL) {
        printf("Original: %s\n", original);
        printf("Copy: %s\n", p);
        free(p);  
    }
    return 0;
}
