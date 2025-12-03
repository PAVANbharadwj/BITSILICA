#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    char ch;
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    printf("Enter character to count occurance: ");
    scanf(" %c", &ch);
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ch){
            count++;
        }
    }
    printf("Character '%c' occurs %d times in the string.\n", ch, count);
    return 0;
}