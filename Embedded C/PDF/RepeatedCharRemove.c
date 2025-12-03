#include<stdio.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    for(int i=0;str[i]!='\0';i++){
        for(int j=i+1;str[j]!='\0';j++){
            if(str[i]==str[j]){
                for(int k=j;str[k]!='\0';k++){
                    str[k]=str[k+1];
                }
                j--;
            }
        }
    }
    printf("String after removing repeated characters: %s\n", str);
    return 0;
}