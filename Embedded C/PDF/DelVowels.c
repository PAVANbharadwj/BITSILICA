#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    char vowels[] = "aeiouAEIOU";
    for(int i=0; str[i]!='\0'; i++){
        int isVowel = 0;
        for(int k=0; vowels[k]!='\0'; k++){
            if(str[i] == vowels[k]){
                isVowel = 1;
                break;
            }
        }
        if(isVowel){
            for(int j=i; str[j]!='\0'; j++){
                str[j] = str[j+1];
            }
            i--;
        }
    }
    printf("String after removing vowels: %s\n", str);
    return 0;
}