#include<stdio.h>
int main(){
    int n;
    printf("enter n value: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    printf("largest %d",max);
}