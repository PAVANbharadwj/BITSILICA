#include <stdio.h>
#include <string.h>

int main() {
    char str[100], substr[100];
    int l1,l2;

    printf("Enter main string: ");
    scanf(" %[^\n]", str);

    printf("Enter substring to search: ");
    scanf("%s", substr);

    l1 = strlen(str);
    l2 = strlen(substr);

    int found = 0;
    for (int i = 0; i <= l1-l2; i++) {
        int j;
        for (j = 0; j < l2; j++) {
            if (str[i + j] != substr[j])
                break;
        }
        if (j == l2) {
            printf("Found at index: %d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Substring not found.\n");
    }

    return 0;
}
