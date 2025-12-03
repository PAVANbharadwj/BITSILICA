#include<stdio.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    char temp[100];
    int i=0;
    for(i=0;str[i]!='\0';i++){
        temp[i]=str[i];
    }
    temp[i] = '\0';
    printf("Copied string is: %s\n", temp);
    return 0;
}