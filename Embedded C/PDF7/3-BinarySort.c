#include<stdio.h>
int binary(int *arr, int n, int key){
    int start=0, end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
    if(arr[mid]==key)
    return mid;
    else if(arr[mid<key])
    start=mid+1;
    else
    end=mid-1;
    }
    return 1;
}
    

int main(){
    int n,key;
    printf("enter n value: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    int result=binary(arr,n,key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    return 0;
}