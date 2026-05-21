#include <stdio.h>
int stringLength(char str[])
{
if (str[0] == '\0')
return 0;
return 1 + stringLength(str + 1);
}
int main()
{
char str[100];
printf("Enter a string: ");
scanf("%s", str);
printf("Length of string: %d\n", stringLength(str));
}
