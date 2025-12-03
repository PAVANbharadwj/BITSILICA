/*
#include<stdio.h>
int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
o/p: *****
     *****
     *****
     *****
     *****
*/
/*
#include<stdio.h>
int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
o/p:
*
**
***
****
*****
*/
/*
#include<stdio.h>
int main(){
    for(int i=5;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
o/p:
*****
****
***
**
*
*/
/*
#include<stdio.h>
int main(){
    for(int i=1;i<=6;i++){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}
o/p:
1
12
123
1234
12345
123456
*/
/*
#include<stdio.h>
int main(){
    for(int i=6;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}
o/p:
123456
12345
1234
123
12
1
*/
#include<stdio.h>
int main(){
    for(int i=0;i<=4;i++){
        for(int j=0;j<=4;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}