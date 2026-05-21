#include <stdio.h>
int add(int a, int b);
int main() {
    int result;
    result = add(5, 6);
    printf("The total is : %d\n", result);
    return 0;
}
int add(int a, int b)
{
return a + b;
}
