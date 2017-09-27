#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void NextPermutation(char *str)
{
    //从后往前找到第一个不是升序的字符的位置的索引idx
    int idx = strlen(str) - 1;
    while(idx >= 1)
    {
        int num1 = str[idx] - '0';  //后一个
        int num2 = str[idx - 1] - '0';  //前一个
        --idx;
        if(num1 > num2)
        {
            break; 
        }
    }
    //printf("%c\n", str[idx]);         //test: 1
    
    //区间[idx + 1, strlen(str)-1]中找到比str[idx]值大, 且在区间中是最小的值
    int min = INT_MAX;
    int min_idx = 0;
    for(int i = idx + 1; i <= strlen(str) - 1; i++)
    {
        if((str[i] - '0')< min && (str[i] - '0') > (str[idx] - '0'))
        {
            min = str[i] - '0';
            min_idx = i;
        }
    }
    //swap(str[idx], str[min_idx])
    char ctmp = str[idx];
    str[idx] = str[min_idx];
    str[min_idx] = ctmp;
    //将区间[idx..strlen(str)-1]的值反转
    char *pstart = str + idx + 1;
    char *pend = str + strlen(str) - 1;
    while(pstart <= pend)
    {
        char ctmp = *pstart;
        *pstart = *pend;
        *pend = ctmp;

        ++pstart;
        --pend;
    }
}

int main(int argc, char *argv[])
{
    //char str[] = "21543";
    //char str[] = "926520";
    //char str[] = "321";
    char str[] = "23133";
    printf("%s 的下一个排列串是: ", str);
    NextPermutation(str);
    printf("%s\n", str);
    
    return 0;
}