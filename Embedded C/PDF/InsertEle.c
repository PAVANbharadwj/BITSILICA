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
    int element;
    printf("Enter the element to insert at the end: ");
    scanf("%d", &element);  
    int position;
    printf("Enter the position to insert the element: ");
    scanf("%d", &position);
    if(position < 0 || position > n) {
        printf("Invalid position!\n");
        return 1;
    }
    for(int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    n++;
    printf("Array after insertion:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}