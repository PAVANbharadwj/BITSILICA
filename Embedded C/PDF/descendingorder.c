#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    int n=strlen(str);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(str[j]<str[j+1]){
                char temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
    printf("Sorted string in descending order: %s\n", str);
    return 0;
}