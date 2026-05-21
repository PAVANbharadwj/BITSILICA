#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    char **names;  
    char temp[100];
    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar();
    names = (char **)malloc(n * sizeof(char *));
    if (names == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0'; 
        names[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(names[i], temp);
    }
    printf("\nNames entered:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", names[i]);
    }
    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);
}
