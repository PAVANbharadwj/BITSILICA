#include <stdio.h>
#include <string.h>
#define MAX 1000

void replaceSubstring(char *str, const char *oldWord, const char *newWord) {
    char result[MAX];
    int i = 0, j = 0;
    int oldLen = strlen(oldWord);
    int newLen = strlen(newWord);

    while (str[i] != '\0') {
        if (strstr(&str[i], oldWord) == &str[i]) {
            strcpy(&result[j], newWord);
            j += newLen;
            i += oldLen;
        } else {
            result[j++] = str[i++];
        }
    }
    result[j] = '\0';
    strcpy(str, result); 
}

int main() {
    char str[MAX], oldWord[100], newWord[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 
    printf("Enter the substring to replace: ");
    scanf("%s", oldWord);
    printf("Enter the new substring: ");
    scanf("%s", newWord);
    replaceSubstring(str, oldWord, newWord);
    printf("Modified string: %s\n", str);
    return 0;
}
