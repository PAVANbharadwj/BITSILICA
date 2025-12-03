#include<stdio.h>
int main(){
    int n1, n2;
    printf("Enter the size of first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d elements for first array: ", n1);
    for(int i = 0; i < n1; i++){
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements for second array: ", n2);
    for(int i = 0; i < n2; i++){
        scanf("%d", &arr2[i]);
    }
    if(n1 == n2){
        printf("Both arrays are of equal size.\n");
    } 
    else {
        printf("Arrays are of different sizes.\n");
    }
    return 0;
}