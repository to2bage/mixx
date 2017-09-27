#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ZeroOfSum(int *arr, int sz)
{
    int *dp = (int *)malloc(sz * sizeof(int));
    memset(dp, 0, sz * sizeof(int));

    for(int i = 0; i < sz; i++)
    {
        if(i == 0)
        {
            dp[i] = arr[i];
        }
        else
        {
            dp[i] = dp[i - 1] + arr[i];
        }
    }

    for(int i = 0; i < sz - 1; i++)
    {
        for(int j = 0; j < sz - i - 1; j++)
        {
            if(dp[j] > dp[j + 1])
            {
                int tmp = dp[j];
                dp[j] = dp[j + 1];
                dp[j + 1] = tmp;
            }
        }
    }

    int min = 1000;
    for(int i = 0; i < sz - 1; i++)
    {
        if(abs(dp[i + 1] - dp[i]) < min)
        {
            min = dp[i + 1] - dp[i];
        }  
    }

    return min;
}

int main(int argc, char *argv[])
{
    int arr[] = {1,-2,3,10,-4,7,2,-5};
    int r = ZeroOfSum(arr, sizeof(arr)/sizeof(int));
    printf("r = %d\n", r);

    return 0;
}