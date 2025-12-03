#include<stdio.h>

void fin(int num){
    int a=0,b=1,c;
    for(int i=0;i<num;i++){
        printf("%d ",a);
        c=b+a;
        a=b;
        b=c;
    }
}

int main(){
    int n;
    printf("enter n value: ");
    scanf("%d",&n);
    printf("Fibnocci series: ");
    fin(n);
    return 0;
}