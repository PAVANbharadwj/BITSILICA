#include<stdio.h>
int main(){
    char str1[100],str2[100];
    char *p1,*p2;
    printf("Enter string1: ");
    scanf(" %[^\n]",str1);
    printf("Enter string2: ");
    scanf(" %[^\n]",str2);
    p1 = str1;
    while (*p1 != '\0') {
        p1++;
    }
    p2 = str2;
    while (*p2 != '\0') {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
    printf("Concatnated strings: %s",str1);
    return 0;
}