#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    int res = atoi(str);
    printf("The string as an integer is: %d\n", res);
    return 0;
}