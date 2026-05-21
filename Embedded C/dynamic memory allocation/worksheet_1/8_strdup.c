#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char original[] = "Embedded Systems";
    int len = strlen(original);
    char *copy = (char *)malloc((len + 1) * sizeof(char));
    if (copy == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    strcpy(copy, original);
    printf("Original: %s\n", original);
    printf("Copy: %s\n", copy);
    free(copy);
}