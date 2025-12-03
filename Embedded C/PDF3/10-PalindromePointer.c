#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isPalindrome(char *str) {
    char *left = str;
    char *right = str + strlen(str) - 1;
    while (left < right) {
        while (left < right && !isalnum(*left)) left++;
        while (left < right && !isalnum(*right)) right--;
            if (tolower(*left) != tolower(*right))
                return 0;
                left++;
                right--;
    }
    return 1; 
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]",str);
    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
    return 0;
}