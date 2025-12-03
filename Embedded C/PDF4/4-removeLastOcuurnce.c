#include<stdio.h>
#include<string.h>
int main(){
    char str[50];
    printf("Enter a string: ");
    scanf(" %[^\n]",str);
    char ch;
    printf("Enter char to remove at last: ");
    scanf(" %c",&ch);
     int lastIndex = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            lastIndex = i;
        }
    }
    if (lastIndex != -1) {
        for (int i = lastIndex; str[i] != '\0'; i++) {
            str[i] = str[i + 1];
        }
    }

    printf("%s",str);
    return 0;
}