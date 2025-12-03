#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    char ch;
    printf("Enter character to insert: ");
    scanf(" %c", &ch);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            str[i] = ch;
        }
    }
    printf("String after addind at the space: %s\n", str);
    return 0;
}