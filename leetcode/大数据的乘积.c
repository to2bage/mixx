#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) 
{
    int len = strlen(num1) + strlen(num2);
    //printf("len = %d\n", len);                                //test: 3
    char *rect = (char *)malloc((len + 1) * sizeof(char));
    memset(rect, '0', (len + 1) * sizeof(char));
    rect[strlen(rect)-1] = 0;
    //printf("%lu\n", strlen(rect));                            //test: 3

    int cnt = strlen(rect) - 1;
    int carry = 0;
    int k = 0;
    for(int i = strlen(num1) - 1; i >= 0; i--)
    {
        cnt = strlen(rect) - 1 - k;
        for(int j = strlen(num2) - 1; j >= 0; j--)
        {
            int n1 = num1[i] - '0';
            int n2 = num2[j] - '0';
            int r = rect[cnt] - '0';
            int tmp = n1 * n2 + r + carry;
            rect[cnt] = tmp % 10 + '0';
            carry = tmp / 10;
            cnt--;
        }
        //此时要判断carry是几位数, 隐形的使得carry == 0
        while(carry)
        {
            rect[cnt] = carry % 10 + '0';
            carry /= 10;
            cnt--;
        }
        k++;
    }
    printf("cnt = %d\n", cnt);
    return rect;
}

int main(int argc, char *argv[])
{
    //char num1[] = "508591";
    //char num2[] = "41609063";               //21161994960233
    //char num1[] = "10";
    //char num2[] = "10";
    char *rect = multiply(num1, num2);
    printf("rect = %s\n", rect);
    for(int i = 0; i < 7; i++)
    {
        printf("%2c", rect[i]);
    }
    printf("\n");

    return 0;
}