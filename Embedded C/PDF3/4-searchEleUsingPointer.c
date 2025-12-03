#include<stdio.h>
void search(int *arr,int n,int ele){
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            printf("Ele found at %d",i);
            return;
        }
    }
}
int main(){
    int n;
    printf("enter n value: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter ele into array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ele;
    printf("Enter ele to search: ");
    scanf("%d",&ele);
    search(arr,n,ele);
    return 0;
}