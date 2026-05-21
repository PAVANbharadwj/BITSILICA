#include <stdio.h>
#include <string.h>
int main()
{
    char arr[100], temp[100];
    int flag = 1;
    printf("Enter a string: ");
    fgets(arr, sizeof(arr), stdin);
    if (arr[strlen(arr) - 1] == '\n')
        arr[strlen(arr) - 1] = '\0';
    int n = strlen(arr);
    int r = 0;
    for (int j = n - 1; j >= 0; j--)
    {
        temp[r++] = arr[j];
    }
    temp[r] = '\0';
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (temp[i] != arr[i])
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("It is a palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
