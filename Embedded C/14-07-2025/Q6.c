#include<stdio.h>
void rotate(int arr[], int n, int k){
    k=k%n;
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i] = arr[i];
    }
    for(int i=0;i<n-k;i++){
        arr[i] = arr[i+k];
    }
    for(int i=0;i<k;i++){
        arr[n-k+i] = temp[i];
    }
}
    void printarr(int arr[], int n){
        for(int i=0;i<n;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
}
int main(){
    int n, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);
    
    rotate(arr, n, k);
    
    printf("Array after rotation: ");
    printarr(arr, n);
    
    return 0;
}