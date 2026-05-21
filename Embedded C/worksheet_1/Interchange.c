#include<stdio.h>
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    int min=0,max=0;
    for(int i=0;i<n;i++){
        if(arr[i]<arr[min]){
            min=i;
        }
        if(arr[i]>arr[max]){
            max=i;
        }
    }
    int temp = arr[min];
    arr[min] = arr[max];
    arr[max] = temp;
    
    printf("Array after swapping: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}