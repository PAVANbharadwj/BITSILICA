#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int arr[n];
    float sum = 0.0;
    printf("Enter %d natural numbers:\n", n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
        sum+= arr[i];
    }
    float avg=(float)sum/n;
    printf("Average of first %d natural numbers is: %.2f\n", n, avg);
    return 0;
}