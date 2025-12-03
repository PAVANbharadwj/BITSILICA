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
    int index;
    printf("Enter the index to delete the element: ");
    scanf("%d", &index);
    if(index < 0 || index >= n) {
        printf("Invalid index!\n");
        return 1;
    }
    for(int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Array after deletion:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}