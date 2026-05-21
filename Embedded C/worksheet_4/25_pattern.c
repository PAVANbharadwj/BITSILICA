#include <stdio.h>

int main()
{
    int n;

    printf("Enter size of X: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) 
        {
            if(i == j || j == n - 1 - i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }   
}