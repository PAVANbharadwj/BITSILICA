#include<stdio.h>
int main(){
    int n;
    printf("Enter n value: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    printf("sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}