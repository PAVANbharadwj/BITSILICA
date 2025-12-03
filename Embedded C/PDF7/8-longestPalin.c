#include <stdio.h>
#include <string.h>

int palindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[200];
    printf("Enter a string: ");
    scanf(" %[^\n]", str); 

    int maxLen = 1, start = 0;
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (palindrome(str, i, j) && (j - i + 1 > maxLen)) {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLen; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
