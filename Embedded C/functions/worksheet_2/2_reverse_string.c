#include <stdio.h>
#include <string.h>
void reverse(char str[], int index) {
    if (index < 0)
        return;
    
    printf("%c", str[index]);
    reverse(str, index - 1);
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    printf("Reversed string: ");
    reverse(str, len - 1);
}
