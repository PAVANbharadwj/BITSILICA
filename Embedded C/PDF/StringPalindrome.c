#include<stdio.h>
#include<string.h>
int main() {
    char str[100],temp[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int i,start=0,end=strlen(str)-1;
    strcpy(temp, str);
    while(start<end){
        char ch=str[start];
        str[start]=str[end];    
        str[end]=ch;
        start++;
        end--;
    }
    if(strcmp(str,temp) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }   
    return 0;
}