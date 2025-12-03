#include<stdio.h>
int compare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2)
            return 0; 
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}


int main() {
    char str1[100], str2[100], result[200];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    if (compare(str1, str2))
        printf("Strings are equal.\n");
    else
        printf("Strings are not equal.\n");
    return 0;
}