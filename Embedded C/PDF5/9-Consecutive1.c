#include<stdio.h>
int main(){
    int n;
    printf("Enter n value: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     int Count = 0, currentCount = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            currentCount++;
            if(currentCount > Count)
                Count = currentCount;
        } 
        else {
            currentCount = 0;
        }
    }
    printf("Count of consecutive 1's is: %d",Count);
    return 0;
}