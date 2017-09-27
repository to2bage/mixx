#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char* str) 
{
    if(str == NULL || strlen(str) == 0)
    {
        return 0;
    }

    //去除空格:注意只能取出字符串前面和后面的空格, 中间的空格不能去除
    char *pstart = str;
    char *pend = str + strlen(str) - 1;
    while(pend >= pstart && *pend == ' ')
    {
        pend--;
    } 
    if(pend < pstart)
    {
        return 0;
    }
    if(pend >= pstart && *pend != ' ')
    {
        *(pend + 1) = '\0';             //去除了字符串尾部的空格
    }
    while(pstart <= pend && *pstart == ' ')
    {
        pstart++;
    }
    str = pstart;
    printf("去除空格后的字符串: %s\n", str);             //test

    //判断正负数
    int sign = 0;       //+
    if(*str == '-')
    {
        sign = 1;       //-
    }
    
    unsigned long long rect = 0;
    char *px = NULL;
    if(sign == 0)
    {
        px = *str == '+' ? str + 1 : str;
    }
    else if(sign == 1)
    {
        px = str + 1;
    }

    while(*px != '\0' && *px != '.' && *px >= '0' && *px <= '9')
    {
        rect *= 10;
        rect += *px - '0';

        px++;
    }

    if(sign == 0)
    {
        //正数
        if(rect > 2147483647 || rect > 9223372036854775807)
        {
            printf(">");
            return 2147483647;
        }
        else
        {
            return rect;
        }
    }
    else if(sign == 1)
    {
        //负数
        if(rect > 2147483648 || rect > 9223372036854775808)
        {
            return -2147483648;
        }
        else
        {
            return -rect;
        }
    }





/*
    rect = sign == 1 ? -rect : rect;
    printf("rect = %lld\n", rect);             //test
    if(rect > 2147483647 || rect > 9223372036854775807)
    {
        printf(">");
        return 2147483647;
    }
    else if(rect < -2147483648 || rect < -9223372036854775808)
    {
        printf("<");
        return -2147483648;
    }
    else
    {
        printf("==");
        return rect;
    }
*/
}

int main(int argc, char *argv[])
{
    int r1 = atoi("123.56");
    printf("123.56 => %d\n", r1);           //123
    int r2 = atoi("123abd456");
    printf("123abd456 => %d\n", r2);        //123
    int r3 = atoi("01   0   ");
    printf("01   0   => %d\n", r3);         //特别注意: 输出1
    int r4 = atoi("   ");
    printf("    => %d\n", r4);              //0

    //char str[] = "01   0   ";
    char str[] = "1";
    int r = myAtoi(str);
    printf("r = %d\n", r);

    return 0;
}