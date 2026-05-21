#include<stdio.h>
int power(int base,int exp){
    int res=1;
    while(exp!=0){
        res*=base;
        exp--;
    }
    return res;
}
int main(){
    int n;
    printf("enter n value ");
    scanf("%d",&n);
    int org=n;
    int rem=0,rev=0,count=0;
    int temp=n;
    while(temp!=0){
        count++;
        temp/=10;
    }
    temp=n;
    while(temp!=0){
        rem=temp%10;
        rev+=power(rem,count);
        temp/=10;
    }
    if(org==rev){
        printf("Armstromg");
    }
    else{
        printf("Not Armstrong");
    }
    return 0;
}