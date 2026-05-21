#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("project.txt", "r+");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *buffer = (char*) malloc(filesize + 1);
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return 1;
    }

    size_t bytesRead = fread(buffer, sizeof(char), filesize, fp);
    buffer[bytesRead] = '\0';

    printf("Original File Content:\n%s\n", buffer);
    char *ptr = buffer;
    while (*ptr != '\0') {
        if (*ptr >= 'a' && *ptr <= 'z') *ptr -= 32; 
        ptr++;
    }

    FILE *fp_out = fopen("output.txt", "w");
    if (fp_out == NULL) {
        printf("Failed to open output file.\n");
        free(buffer);
        fclose(fp);
        return 1;
    }

    fwrite(buffer, sizeof(char), bytesRead, fp_out);

    free(buffer);
    fclose(fp);
    fclose(fp_out);

    printf("Modified content written to output.txt\n");

    return 0;
}

