#include<stdio.h>
#include<string.h>
int sort(char str[]){
    int n=strlen(str);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(str[j]>str[j+1]){
                char temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }                           
}                
int main(){
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    if(strlen(str1) != strlen(str2)){
        printf("The strings are not anagrams.\n");
        return 0;
    }
    sort(str1);
    sort(str2);
    if(strcmp(str1, str2) == 0){
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }
    return 0;
}