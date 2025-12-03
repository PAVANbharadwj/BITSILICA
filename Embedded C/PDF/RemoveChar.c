#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    char ch;
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    printf("Enter character to remove: ");
    scanf(" %c", &ch);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] == ch){
            for(int j=i;j<len;j++){
                str[j] = str[j+1];
            }
            len--; 
            i--; 
        }
    }
    printf("String after removing '%c': %s\n", ch, str);
    return 0;
}