#include <stdio.h>
int main()
{
    char f1[50], f2[50];
    printf("Enter first file: ");
    scanf("%s", f1);
    printf("Enter second file: ");
    scanf("%s", f2);

    FILE *fp1 = fopen(f1, "r");
    FILE *fp2 = fopen(f2, "r");

    if(!fp1 || !fp2)
    {
        printf("Error opening files.\n");
        return 0;
    }

    char ch1, ch2;
    int same = 1;

    while(1)
     {
        ch1 = getc(fp1);
        ch2 = getc(fp2);

        if(ch1 != ch2)
        {
            same = 0;
            break;
        }

        if(ch1 == EOF || ch2 == EOF)
            break;
    }

    fclose(fp1);
    fclose(fp2);

    if(same)
        printf("Files are IDENTICAL\n");
    else
        printf("Files are DIFFERENT\nn");

    return 0;
}
