#include <stdio.h>
int main()
 {
    int n, result;
    printf("Enter a number: ");
    scanf("%d", &n);
    result = (n << 3) + n; 
    printf("Result=%d\n", result);
    return 0;
}
