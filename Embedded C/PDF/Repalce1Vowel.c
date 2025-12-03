#include<stdio.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    char vowels[] = "aeiouAEIOU";
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]==vowels[i]){
            str[i]='-';
        }
    }
    printf("String after replacing first vowels with '-': %s\n", str);
    return 0;
}