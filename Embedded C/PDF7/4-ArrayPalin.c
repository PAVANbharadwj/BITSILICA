#include<stdio.h>

int palin(int arr[], int n){
    for(int i=0;i<n/2;i++){
        if(arr[i]!=arr[n-i-1])
            return 0;
    }
    return 1;
}

int main(){
    int n;
    printf("Enter n value: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:" );
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    if(palin(arr,n)){
        printf("Given string is palindrome.");
    }
    else{
        printf("Given string is not palindrome.");
        }
    return 0;
}