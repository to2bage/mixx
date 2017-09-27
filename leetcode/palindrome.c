#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) 
{
    int tmp = x;
    int ret = 0;
    while(tmp)
    {
        ret *= 10;
        ret += tmp % 10;
        tmp /= 10;
    }
    return x == ret ? true : false;
}

int main(int argc, char *argv[])
{
    int x = 100;
    bool b = isPalindrome(x);
    
}
