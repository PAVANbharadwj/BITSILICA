#include<stdio.h>
int main(){
    int arr[99];
    int total = 100*101/2;
    int sum = 0;
    printf("Enter 99 numbers (1 to 100):\n");
    for(int i = 0; i < 99; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int missingNumber = total - sum;
    printf("The missing number is: %d\n", missingNumber);
    return 0;
}