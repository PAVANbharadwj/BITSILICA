#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char str[100];
    char alpha[100] = "", digit[100] = "", special[100] = "";
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    for(int i = 0; str[i] != '\0'; i++){
        if(isalpha(str[i])){
            strncat(alpha, &str[i],1);
        }
        else if(isdigit(str[i])){
            strncat(digit, &str[i],1);
        }
        else if(!isspace(str[i])){
            strncat(special, &str[i],1);
        }
    }
    printf("Alphabets: %s\n", alpha);
    printf("Digits: %s\n", digit);
    printf("Special Characters: %s\n", special);
    return 0;
}