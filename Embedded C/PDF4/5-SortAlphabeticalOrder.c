#include<stdio.h>
#include<string.h>
int main(){
    char str[50];
    printf("enter a string: ");
    scanf(" %[^\n]",str);
    int n=strlen(str)-1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(str[j]>str[j+1]){
                int temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
    printf("Sorted string: %s",str);
    return 0;
}