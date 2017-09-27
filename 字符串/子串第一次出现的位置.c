#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//暴力:BruteForce
int BruteForceSearch(char *str, char *substr)
{
    if(str == NULL || substr == NULL)
    {
        return -1;
    }

    int stri = 0;  //字符串的起始索引
    int substrj = 0;  //子串的起始索引
    int substrlen = strlen(substr);     //子串的长度
    int strlast = strlen(str) - substrlen;  //字符串的最后的索引位置, 包含

    while(stri <= strlast && substrj < substrlen)
    {
        if(str[stri + substrj] == substr[substrj])
        {
            substrj++;
        }
        else
        {
            stri++;
            substrj = 0;        //模式字符串的回漱
        }
    }

    if(substrj >= substrlen)
    {
        return stri;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    char substr[] = "def";
    int r = BruteForceSearch(str, substr);
    printf("第一次出现的位置: %d\n", r);

    return 0;
}