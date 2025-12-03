#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[]={1, 2, 3, 4, 5};
    int length=(sizeof(arr)/sizeof(arr[0]));
    printf("Length of the array is: %d\n", length);
    return 0;
}