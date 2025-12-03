#include<stdio.h>
int main(){
    char str[100];
    int freq[256]={0};
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    for(int i=0; str[i]!='\0'; i++){
        freq[(unsigned char)str[i]]++;
    }
    printf("Unique characters in the string are: ");
    for(int i=0; str[i]!='\0'; i++){
        if(freq[(unsigned char)str[i]] == 1){
            printf("%c ", str[i]);
        }
    }
    return 0;
}