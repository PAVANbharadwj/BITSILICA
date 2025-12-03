#include<stdio.h>
int ispresent(int arr[], int size, int num) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == num) {
            return 1; 
        }
    }
    return 0; 
}
int main(){
    int arr1[]={1, 2, 3, 4, 5};
    int arr2[]={2, 3, 1, 0, 5};
    int i;
    for(i=0; i<5; i++){
        if(!ispresent(arr2, 5, arr1[i])) {
            printf("%d ", arr1[i]);
            break;
        }
    }
    return 0;
}