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
    if(n > 0) {
        n--;
    }
    printf("Array after deleting last element: ");
    for(int i = 0; i < n; i++){ 
        printf("%d ", arr[i]);
    }   
    return 0;
}