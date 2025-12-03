#include<stdio.h>
int main(){
    int n;
    printf("enter n value: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    printf("enter element to search: ");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            printf("%d element found at index %d",k,i);
            break;
        }
    }
    return 0;
}