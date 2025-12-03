#include<stdio.h>
int main(){
    int n1,n2;
    printf("Enter n1 value: ");
    scanf("%d",&n1);
    int arr1[n1];
    printf("Enter array1 elements: ");
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter n2 value: ");
    scanf("%d",&n2);
    int arr2[n2];
    printf("Enter array2 elements: ");
    for(int i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    int n3=n1+n2;
    int merg[n3];
    for(int i=0;i<n1;i++){
        merg[i]=arr1[i];
    }
    for(int i=0;i<n2;i++){
        merg[n1+i]=arr2[i];
    }
    printf("Merged array:");
    for(int i=0;i<n3;i++){
        printf("%d",merg[i]);
    }
    return 0;
}