#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "abcabcbb";
    int last[256], length = strlen(s);
    
    for(int i = 0; i < 256; i++)
        last[i] = -1;

    int start = 0, maxLen = 0;

    for(int end = 0; end < length; end++) 
    {
        if(last[(int)s[end]] >= start)
            start = last[(int)s[end]] + 1;

        last[(int)s[end]] = end;

        if(end - start + 1 > maxLen)
            maxLen = end - start + 1;
    }

    printf("Longest unique substring length = %d", maxLen);
}