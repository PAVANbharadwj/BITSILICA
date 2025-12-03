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
    int k;
    printf("Enter the number of positions to rotate Right: ");
    scanf("%d", &k);
    k=k%n;
    for(int i=0;i<n;i++){
        if(i<n-k){
            printf("%d ", arr[i+(n-k)]);
        } else {
            printf("%d ", arr[i-(n-k)]);
        }
    }
    return 0;
}