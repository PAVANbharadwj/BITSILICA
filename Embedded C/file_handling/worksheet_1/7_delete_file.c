#include <stdio.h>

int main() 
{
    char filename[100];

    printf("Enter file name to delete: ");
    scanf("%s", filename);
    if (remove(filename) == 0) 
    {
        printf("File deleted successfully.\n");
    } else 
    {
        printf("Error: Could not delete the file.\n");
    }

    return 0;
}
