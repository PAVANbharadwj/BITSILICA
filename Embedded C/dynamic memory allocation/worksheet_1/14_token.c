#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a;
    char *ptr;
    char *token;
    printf("Enter maximum number of characters: ");
    scanf("%d", &a);
    getchar(); 
    ptr = (char *)malloc(a * sizeof(char));
    printf("Enter a sentence: ");
    fgets(ptr, a, stdin);
    ptr[strcspn(ptr, "\n")] = '\0'; 
    token = strtok(ptr, " ");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    free(ptr);
}
