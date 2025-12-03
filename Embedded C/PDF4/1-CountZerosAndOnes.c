#include<stdio.h>
int main(){
    unsigned int n;
    printf("enter n value: ");
    scanf("%lu",&n);
    int zero=0,one=0;
    while(n!=0){
        if((n&1)==1){
            one++;
        }
        else{
            zero++;
        }
        n=n>>1;
    }
    printf("ZEROS:%d, ONES:%d",zero,one);
}