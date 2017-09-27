/*
    给定两个串a和b, 问b是否是a的子串的变位词
    1.滑动窗口的思想: 动态维护一个窗口
      比如b的长度是3, 考察a[0..2],[1..3],[2..4]是否和b是变位词
    2.hash数组, c/c++[0..255].java[0..65535]
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isBianhuanWord(char *a, char *b)
{
    if(strlen(a) < strlen(b))
    {
        return false;
    }

    int lenb = strlen(b);       //字符串b的长度, 字符串a开的窗口大小
    int lena = strlen(a);
    int *num = (int *)malloc(lenb * sizeof(int));
    memset(num, 0, lenb * sizeof(int));
    int nonZero = 0;        //记录数组num中非0字符的个数
    //将字符串b的字符映射到num数组中, 即num[i]表示b中的某个字符出现的次数
    for(int i = 0; i < lenb; i++)
    {
        num[b[i] - 'a']++;
        if(num[b[i] - 'a'] == 1)
        {
            nonZero++;
        }
    }
    //用b中某个字符出现的次数减去a中对应的字符出现的个数
    //如果num数组全部为0, 即nonZero== 0,则找到了这个变换词b
    //以下代码是a第一个窗口
    /*
    for(int i = 0; i < lenb; i++)
    {
        int tmp = a[i] - 'a';
        --num[tmp];
        if(num[tmp] == 0)
        {
            nonZero--;
        }
        else if(num[tmp] == -1)
        {
            nonZero++;
        }
    }
    if(nonZero == 0)
    {
        //如果nonZero==0表示a窗口中的字符和b中的字符是一样的
        return true;
    }
    */

    for(int i = 0; i <= lena - lenb; i++)
    {
        //
        nonZero = 0;
        for(int k = 0; k < lenb; k++)
        {
            num[b[k] - 'a']++;
            if(num[b[k] - 'a'] == 1)
            {
                nonZero++;
            }
        }
        //
        for(int j = i; j < lenb + i; j++)
        {
            int tmp = a[j] - 'a';
            --num[tmp];
            if(num[tmp] == 0)
            {
                nonZero--;
            }
            else if(num[tmp] == -1)
            {
                nonZero++;
            }
        }
        if(nonZero == 0)
        {
            return true;
        }
    }
    
    return false;
}


int main(int argc, char *argv[])
{
    char a[] = "hello";
    char b[] = "ole";
    bool br = isBianhuanWord(a, b);
    if(br == true)
    {
        printf("%s是变换词\n", b);
    }
    else if(br == false)
    {
        printf("%s不是变换词\n", b);
    }

    return 0;
}