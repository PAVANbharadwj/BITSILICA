#include<stdio.h>

void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseWords(char *str) {
    char *start = str;
    char *end = str;
    while (*end) end++;
    end--;
    reverse(start, end);
    char *word_start = str;
    while (*str) {
        if (*str == ' ') {
            reverse(word_start, str - 1);
            str++;
            word_start = str;
        } else {
            str++;
        }
    }
    reverse(word_start, str - 1);
}

int main(){
    char str[100];
    printf("Enter string: ");
    scanf("%[^\n]",str);
    char *p = str;
    while (*p) {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
        p++;
    }
    reverseWords(str);
    printf("Reversed words: %s\n", str);
    return 0;
}