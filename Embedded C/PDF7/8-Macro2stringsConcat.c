/*
#include <stdio.h>
#define CONCAT_STRINGS(a, b) a b
int main() {
    char *combined = CONCAT_STRINGS("Hello, ", "Hemu!");
    printf("%s\n", combined);
    return 0;
}
*/


#include <stdio.h>

#define CONCATENATE(s1, s2, result) concatStrings(s1, s2, result)

void concatStrings(char *str1, char *str2, char *result) {
    while (*str1 != '\0') {
        *result = *str1;
        result++;
        str1++;
    }
    while (*str2 != '\0') {
        *result = *str2;
        result++;
        str2++;
    }
    *result = '\0';
}

int main() {
    char str1[100], str2[100], result[200];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    CONCATENATE(str1, str2, result);
    printf("Concatenated string: %s\n", result);
    return 0;
}