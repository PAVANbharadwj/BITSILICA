#include <stdio.h>
int main() 
{
    char file1[50], file2[50];
    printf("Enter main file: ");
    scanf("%s", file1);
    printf("Enter file to append: ");
    scanf("%s", file2);

    FILE *fp1 = fopen(file1, "a");
    FILE *fp2 = fopen(file2, "r");

    if(!fp1 || !fp2) {
        printf("Error opening files.\n");
        return 0;
    }

    char ch;
    fputc('\n', fp1);

    while((ch = getc(fp2)) != EOF)
        putc(ch, fp1);

    fclose(fp1);
    fclose(fp2);

    printf("File appended successfully\n");
    return 0;
}
