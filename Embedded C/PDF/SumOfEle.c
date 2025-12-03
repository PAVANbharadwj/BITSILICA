#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("Sum of elements: %d\n", sum);
    return 0;
}