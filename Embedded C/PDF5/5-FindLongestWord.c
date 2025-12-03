#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    int maxLen = 0, currLen = 0;
    int start = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            if (currLen == 0) 
            start = i;
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
            }
            currLen = 0;
        }
    }
    if (currLen > maxLen)
        maxLen = currLen;
        currLen = 0;
    printf("All longest words of length %d:\n", maxLen);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            if (currLen == 0) start = i;
            currLen++;
        } else {
            if (currLen == maxLen) {
                for (int j = 0; j < currLen; j++)
                    printf("%c", str[start + j]);
                printf("\n");
            }
            currLen = 0;
        }
    }

    if (currLen == maxLen) {
        for (int j = 0; j < currLen; j++)
            printf("%c", str[start + j]);
        printf("\n");
    }

    return 0;
}
