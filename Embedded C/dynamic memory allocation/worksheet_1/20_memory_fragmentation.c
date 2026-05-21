#include <stdio.h>
#include <stdlib.h>
int main() 
{
    char *p1 = malloc(100);
    char *p2 = malloc(200); 
    char *p3 = malloc(50);  
    free(p2);
    char *p4 = malloc(180); 
    if (p4 == NULL)
        printf("Memory allocation failed due to fragmentation!\n");
    else
        printf("Memory allocated successfully.\n");

    free(p1);
    free(p3);
    free(p4);
}
