#include<stdio.h>
int main(){
    int n,index=0;
    printf("Enter n value: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[index++]=arr[i];
        }
    }
    while(index<n){
        arr[index++]=0;
    }
    printf("\nUpdated Array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}