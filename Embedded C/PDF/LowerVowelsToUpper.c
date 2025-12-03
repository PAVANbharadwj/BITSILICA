#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    for(int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            str[i] = toupper(str[i]);
        } 
        else {
            str[i] = tolower(str[i]);
        }
    }
    printf("String after conversion: %s\n", str);
    return 0;
}            