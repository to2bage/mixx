#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetNext(char *str, int *next)
{
    int nlen = strlen(str);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < nlen - 1)
    {
        if(k == -1 || str[j] == str[k])
        {
            ++j;
            ++k;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int main(int argc, char *argv[])
{
    char str[] = "abaabcaba";
    int *next = (int *)malloc(strlen(str) * sizeof(int));
    GetNext(str, next);
    for(int i = 0; i < strlen(str); i++)
    {
        printf("%3d", next[i]);
    }
    return 0;
}