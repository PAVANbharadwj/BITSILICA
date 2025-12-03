#include<stdio.h>
void reverse(int *arr,int n){
    int start=0,end=n-1;
    for(int i=0;i<n;i++){
        while(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }
}

int main(){
    int n;
    printf("Enter n values: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array ele: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    reverse(arr,n);
    printf("reversed array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}