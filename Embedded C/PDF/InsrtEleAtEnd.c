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
    int newElement;
    printf("Enter the element to insert at the end: ");
    scanf("%d", &newElement);
    arr[n]=newElement;
    n++;
    for(int i = 0; i < n; i++){
       printf("%d ", arr[i]);
    }
    return 0;
}