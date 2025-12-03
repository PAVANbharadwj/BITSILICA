#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int vowelCount = 0, consonantCount = 0;
    for(int i=0;str[i]!='\0';i++){
        char ch = tolower(str[i]);
        if(ch >= 'a' && ch <= 'z') {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            } else {
                consonantCount++;
            }
        }
    }
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);
    return 0;
}