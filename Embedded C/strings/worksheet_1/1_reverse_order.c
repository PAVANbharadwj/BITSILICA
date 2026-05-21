#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str,20,stdin); 
    int len = strlen(str);
    int end = len, i;
     printf("Reversed order of words: ");
    for (i = len - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[end] = '\0';        
            printf("%s ", &str[i + 1]);
            end = i;
        }
    }
    printf("%s\n", str);
}
