/*
    一个字符只包含*和数字, 把*放在字符串的开始部分
    循环不变式:[0..i-1]都是*, [i..j-1]都是数字, [j..n-1]未探测的部分
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *changeStarAndNum(char *str)           //改变了字符的顺序
{
    if(str == NULL)
    {
        return NULL;
    }
    for(int i = 0, j = 0; j <= strlen(str); j++)
    {
        if(str[j] == '*')
        {
            char tmp = str[j];
            str[j] = str[i];
            str[i] = tmp;
            i++;
        }
    }
    return str;
}

char *changeStarAndNumber(char *str)        //不会改变字符的顺序
{
    if(str == NULL)
    {
        return NULL;
    }

    int j = strlen(str) - 1;
    for(int i = strlen(str) - 1; i >= 0; i--)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            str[j--] = str[i];
        }
    }
    for(; j >= 0; j--)
    {
        str[j] = '*';
    }

    return str;
}

int main(int argc, char *argv[])
{
    char str[] = "*01*2*4";
    //char *rect = changeStarAndNum(str);
    char *rect = changeStarAndNumber(str);
    printf("%s\n", rect);
    return 0;
}