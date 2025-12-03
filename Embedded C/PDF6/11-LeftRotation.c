#include <stdio.h>
#include <string.h>

void leftRotate(char *str, int k) {
    int len = strlen(str);
    k = k % len;
    char temp[1000];
    strcpy(temp, str + k);
    strncat(temp, str, k);
    strcpy(str, temp);
}

int main() {
    char str[1000];
    int k;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter number of positions to left rotate: ");
    scanf("%d", &k);

    leftRotate(str, k);
    printf("Left rotated string: %s\n", str);

    return 0;
}
