#include <stdio.h>
int main()
{
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int n = 3;
    int *p = a;
    int *q = b;
    int dot = 0;
    for (int i = 0; i < n; i++)
    {
        dot += (*(p + i)) * (*(q + i));
    }
    printf("Dot product = %d\n", dot);
}