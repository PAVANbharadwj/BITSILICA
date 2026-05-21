#include <stdio.h>
#include <string.h>
int main() {
    char names[10][50];
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    printf("Enter the strings:\n");
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    char temp[50];
    for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
    if(strcmp(names[i], names[j]) > 0)
    { 
        strcpy(temp, names[i]);
        strcpy(names[i], names[j]);
        strcpy(names[j], temp);
    }
    }
    }
    printf("\nStrings in alphabetical order:\n");
    for(int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
}
