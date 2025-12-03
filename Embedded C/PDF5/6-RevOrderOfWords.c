#include<stdio.h>
#include<string.h>
#include<ctype.h>

void reverse(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseWords(char *str) {
    int len = strlen(str);
    reverse(str, 0, len - 1);
    int start = 0, end = 0;
    while (str[start]) {
        if (isspace(str[start])) {
            start++;
            continue;
        }
        end = start;
        while (str[end] && !isspace(str[end])) {
            end++;
        }
        reverse(str, start, end - 1);
        start = end;
    }
}
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]",str);
    reverseWords(str);
    printf("Reversed words of a string: %s",str);
    return 0;
}