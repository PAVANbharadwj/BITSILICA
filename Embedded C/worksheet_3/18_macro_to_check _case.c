#include <stdio.h>

#define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')
#define IS_LOWER(c) ((c) >= 'a' && (c) <= 'z')

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    if (IS_UPPER(ch))
        printf("%c is uppercase.\n", ch);
    else if (IS_LOWER(ch))
        printf("%c is lowercase.\n", ch);
    else
        printf("%c is not an alphabet.\n", ch);
}
