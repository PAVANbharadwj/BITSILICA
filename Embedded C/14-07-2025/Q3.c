#include<stdio.h>
#include<math.h>
int perfect(int num){
    int root=sqrt(num);
    return(root * root == num);
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if(perfect(num)){
        printf("%d is a perfect square\n", num);
    } else {
        printf("%d is not a perfect square\n", num);
    }
    
    return 0;
}