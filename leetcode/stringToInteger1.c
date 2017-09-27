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
    //同时去除正数前面的加号
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
    while(pstart <= pend && (*pstart == ' ' || *pstart == '+'))
    {
        pstart++;
    }
    str = pstart;
    //找到第一个不是数字的字符
    if(*pstart != '-')
    {
        while(*pstart >= '0' && *pstart <= '9')
        {
            pstart++;
        }
        *pstart = '\0';
    }
    else if(*pstart == '-')
    {
        char *px = pstart + 1;
        while(*px >= '0' && *px <= '9')
        {
            px++;
        }
        *px = '\0';
    }
    
    //printf("去除空格和正号后的只有数字字符的字符串: %s\n", str);             //test

    //处理大数据
    if(*str == '-')
    {
        //负数
        char *p = str + 1;
        if(strlen(p) > strlen("2147483648"))
        {
            return -2147483648;
        }
        else if(strlen(p) == strlen("2147483648"))
        {
            //printf("p = %s\n", p);                  //test
            if(strcmp(p, "2147483648") > 0)
            {
                return -2147483648; 
            }
        }
    }
    else
    {
        //正数
        if(strlen(str) > strlen("2147483647"))
        {
            return 2147483647;
        }
        else if(strlen(str) == strlen("2147483647"))
        {
            if(strcmp(str, "2147483647") >= 0)
            {
                return 2147483647;
            }
        }
    }

    //判断正负数
    int sign = 0;       //+
    if(*str == '-')
    {
        sign = 1;       //-
    }
    
    int rect = 0;
    char *px = NULL;
    if(sign == 0)
    {
        //+
        px = str;
    }
    else if(sign == 1)
    {
        //-
        px = str + 1;
    }

    while(*px != '\0' /*&& *px != '.' && *px >= '0' && *px <= '9'*/)
    {
        rect *= 10;
        rect += *px - '0';

        px++;
    }

    //printf("rect = %d\n", rect);                //test

    return sign == 1 ? -rect : rect;

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
    //char str[] = "    +3456abd23 4560  ";   //3456
    //char str[] = "18446744073709551617";
    //char str[] = "2147483647";
    char str[] = "-2147483647";
    int r = myAtoi(str);
    printf("r = %d\n", r);

    {
        //test
        //if(strcmp("-2124", "-13456"))
    }

    return 0;
}