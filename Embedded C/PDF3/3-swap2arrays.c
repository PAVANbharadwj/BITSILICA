#include<stdio.h>
void swap(int *arr1, int *arr2, int n1, int n2){
    int min = (n1 < n2) ? n1 : n2;
    for (int i = 0; i < min; i++) {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}

int main(){
    int n1,n2;
    printf("Enter n1 and n2 values: ");
    scanf("%d%d",&n1,&n2);
    int arr1[n1];
    printf("Eter array1 values: ");
    for(int i=0;i<n1;i++)
        scanf("%d",&arr1[i]);
    int arr2[n2];
    printf("Eter array2 values: ");
    for(int i=0;i<n2;i++)
        scanf("%d",&arr2[i]);
    swap(arr1, arr2, n1, n2);
    printf("Array1 after swap: \n");
    for(int i=0;i<n1;i++)
        printf("%d ",arr1[i]);
    printf("\nArray2 after swap: \n");
    for(int i=0;i<n2;i++){
        printf("%d ",arr2[i]);
    }
    return 0;
}