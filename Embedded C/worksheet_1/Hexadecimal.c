#include<stdio.h>
int main(){
    int n;
    printf("Enter decimal value: ");
    scanf("%d",&n);
    char hexa[20];
    int i=0;
    if(n==0)return 0;
    while(n!=0){
        int rem=n%16;
        if(rem<10)
            hexa[i]=rem+'0';
        else
            hexa[i]=rem - 10 + 'A';
        i++;
        n=n/16;
    }
    printf("HexaDecimal Conversation: ");
    for(int j=i-1;j>=0;j--){
        printf("%c",hexa[j]);
    }
    return 0;
}