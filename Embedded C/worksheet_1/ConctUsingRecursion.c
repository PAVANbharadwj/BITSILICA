#include<stdio.h>
void concat(char *str1,char *str2){
        if(*str1=='\0'){
            while(*str2!='\0'){
                *str1=*str2;
                *str1++;
                *str2++;
            }
            *str1='\0';
            return;
        }
    concat(str1+1,str2);
}

int main(){
    char str1[100],str2[100];
    printf("enter string1: ");
    scanf("%[^\n]",str1);
    printf("enter string2: ");
    scanf(" %[^\n]",str2);
    concat(str1,str2);
    printf("Concatnated sting : %s",str1);
}