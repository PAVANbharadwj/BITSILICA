#include<stdio.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    int sum=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='0' && str[i]<='9'){
            sum+=str[i]-'0';
        }
    }
    printf("Sum of integers in the string is: %d\n", sum);
    return 0;
}