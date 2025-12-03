#include<stdio.h>
#include<ctype.h>
int main(){
    char str[100];
    int alphabetCount = 0, digitCount = 0, specialCharCount = 0;
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])){
            alphabetCount++;
        }
        else if(isdigit(str[i])){
            digitCount++;
        }
        else if(!isspace(str[i])) {
            specialCharCount++;
        }
    }
    printf("Number of alphabets: %d\n", alphabetCount);
    printf("Number of digits: %d\n", digitCount);   
    printf("Number of special characters: %d\n", specialCharCount);    
    return 0;
}