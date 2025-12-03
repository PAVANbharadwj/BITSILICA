#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;
    int len;

    str = (char *)malloc(100 * sizeof(char));
    if (!str) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    printf("Reversed string: %s\n", str);
    free(str);
    return 0;
}