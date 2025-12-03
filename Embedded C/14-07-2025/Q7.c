#include<stdio.h>
int main(){
    int n1,n2;
    printf("Enter n1 and n2 values:");
    scanf("%d %d", &n1, &n2);
    int arr[n1];
    printf("Enter %d elements in the array:\n", n1);
    for(int i=0; i<n1; i++){
        scanf("%d", &arr[i]);
    }
    int arr2[n2];
    printf("Enter %d elements in the second array:\n", n2);
    for(int i=0; i<n2; i++){
        scanf("%d", &arr2[i]);
    }
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(arr[i] == arr2[j]){
                printf("Common element: %d\n", arr[i]);
            }
        }
    }
    return 0;
}