#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() 
{
    char filename[50];
    struct stat info;

    printf("Enter file name: ");
    scanf("%s", filename);
    if (stat(filename, &info) == 0) 
    {
        printf("Last modified: %s", ctime(&info.st_mtime));
    } 
    else
    {
        printf("File not found!\n");
    }
}
