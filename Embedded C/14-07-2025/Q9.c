#include<stdio.h>
int main(){
    int n,sum=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in the array:\n", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    