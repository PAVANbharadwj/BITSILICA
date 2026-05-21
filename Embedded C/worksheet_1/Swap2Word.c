#include <stdio.h>
#include <string.h>

void swapWords(char str[]) {
    char first[100], last[100];
    int i = 0, j = 0, start = 0, end = strlen(str) - 1;
    while (str[i] != ' ' && str[i] != '\0') {
        first[i] = str[i];
        i++;
    }
    first[i] = '\0';
    while (str[end] != ' ' && end >= 0) end--;
    end++;
    while (str[end] != '\0') {
        last[j++] = str[end++];
    }
    last[j] = '\0';
    printf("Swapped sentence: %s", last);
    for (int k = i; str[k] != '\0' && k < end - j; k++) {
        printf("%c", str[k]);
    }
    printf("%s\n", first);
}

int main() {
    char str[200];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 
    swapWords(str);
    return 0;
}