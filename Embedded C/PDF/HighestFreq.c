#include<stdio.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        for(int j=i+1;str[j]!='\0';j++){
            if(str[i]==str[j]){
                count=str[i];
                break;
            }
        }
    }
    if(count == 0) {
        printf("No repeated characters found.\n");
        return 0;
    }
    printf("Highest frequency character is: %c\n", count);
    return 0;
}