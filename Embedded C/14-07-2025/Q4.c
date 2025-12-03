#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    int start,len;
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    printf("Enter the starting index and length of substring: ");
    scanf("%d %d", &start, &len);   
    char str1[100];
    substring(str, start, len, str1);
    printf("Substring: %s\n", str1);
    return 0;
}
int substring(char str[], int start, int len,char str1[]){
    int i;
    for(i=0;i<len;i++){
        str1[i] = str[start + i];
    }
    str1[i] = '\0';
} 