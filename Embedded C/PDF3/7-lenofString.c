#include<stdio.h>
int main(){
    char str[100];
    char *ptr;
    int len;
    printf("Eneter a string: ");
    scanf("%[^\n]",str);
    ptr=str;
    while(*ptr!='\0'){
        len++;
        ptr++;
    }
    printf("Length: %d",len);
    return 0;
}