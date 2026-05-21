#include <stdio.h>
int square(int n) 
{
    int res = 0, x = n;
    while (x) 
    {
        if (x & 1)       
            res += n;       
        n <<= 1;           
        x >>= 1;           
    }
    return res;
}
int main()
{
    int num = 5;
    printf("Square is %d\n",square(num));
}
