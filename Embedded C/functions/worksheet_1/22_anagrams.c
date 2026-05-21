#include <stdio.h>
#include <string.h>
int isAnagram(char str[], char str1[]) {
    int i, j, count = 0;
    int n = strlen(str);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (str[i] == str1[j]) {
                count++;
                break;
            }
        }
    }
    if (count == n)
        return 1;
    else
        return 0;
}
int main() {
    char str[100], str1[100];
    printf("Enter string1: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    printf("Enter string2: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    if (strlen(str) != strlen(str1)) {
        printf("Not anagrams (different lengths)\n");
        return 0;
    }

    if (isAnagram(str, str1))
        printf("True — they are anagram strings.\n");
    else
        printf("Not anagrams.\n");

    return 0;
}
