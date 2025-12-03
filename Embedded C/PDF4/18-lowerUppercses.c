#include <stdio.h>

#define TO_UPPER(c) (((c) >= 'a' && (c) <= 'z') ? ((c) - 32) : (c))
#define TO_LOWER(c) (((c) >= 'A' && (c) <= 'Z') ? ((c) + 32) : (c))

int main() {
    char str[50];
    printf("Enter string: ");
    scanf(" %[^\n]",str);
    printf("Uppercase: ");
    for (int i = 0; str[i]; i++)
        printf("%c", TO_UPPER(str[i]));
    printf("\nLowercase: ");
    for (int i = 0; str[i]; i++)
        printf("%c", TO_LOWER(str[i]));
    return 0;
}
