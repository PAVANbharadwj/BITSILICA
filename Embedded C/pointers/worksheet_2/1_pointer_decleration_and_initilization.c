#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 10;
    float b = 5.5;
    char c = 'X';

    int *ip;
    float *fp;
    char *cp;

    ip = &a;
    fp = &b;
    cp = &c;

    printf("Values via pointers:\n");
    printf("int: %d\n", *ip);
    printf("float: %.2f\n", *fp);
    printf("char: %c\n", *cp);

    int *arr_i = (int *)malloc(3 * sizeof(int));
    float *arr_f = (float *)malloc(3 * sizeof(float));
    char *arr_c = (char *)malloc(4 * sizeof(char));  // +1 if for string

    if (!arr_i || !arr_f || !arr_c) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) 
    {
        arr_i[i] = i * 10;      
        arr_f[i] = i * 1.1f;    
        arr_c[i] = 'A' + i;      
    }

    printf("\nAccessing dynamically allocated memory using pointer arithmetic:\n");
    for (int i = 0; i < 3; i++) {
        printf("int[%d] = %d, ", i, *(arr_i + i));
        printf("float[%d] = %.2f, ", i, *(arr_f + i));
        printf("char[%d] = %c\n", i, *(arr_c + i));
    }

    printf("\nPointer arithmetic example:\n");
    printf("Before increment: arr_i = %p, arr_i + 1 = %p\n", (void*)arr_i, (void*)(arr_i + 1));

    printf("\nTypecasting pointer example:\n");
    int num = 65;  
    int *pnum = &num;
    char *pchar = (char *)pnum; 
    printf("Integer value: %d, Reinterpreted as char: %c\n", *pnum, *pchar);

    free(arr_i);
    free(arr_f);
    free(arr_c);
}
