#include <stdio.h>
#include <string.h>

int main() {
    char f1[50], f2[50], out[50];
    printf("Enter file1 name: ");
    scanf("%s", f1);
    printf("Enter file2 name: ");
    scanf("%s", f2);
    printf("Enter output filename: ");
    scanf("%s", out);

    FILE *fp1 = fopen(f1, "r");
    FILE *fp2 = fopen(f2, "r");
    FILE *ft  = fopen(out, "w");

    if(!fp1 || !fp2 || !ft) {
        printf("Error opening files.\n");
        return 0;
    }

    char line[200];
    while(1) {
        if(fgets(line, sizeof(line), fp1))
            fputs(line, ft);

        if(fgets(line, sizeof(line), fp2))
            fputs(line, ft);

        if(feof(fp1) && feof(fp2))
            break;
    }

    fclose(fp1);
    fclose(fp2);
    fclose(ft);

    printf("Alternate merge completed.\n");
    return 0;
}
