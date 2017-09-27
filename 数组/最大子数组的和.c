#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int MaxOfSum(int *arr, int sz, int *idx_min, int *idx_max)
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

    int max = 0;
    //int idx_min = 0;
    //int idx_max = 0;
    for(int i = 0; i < sz; i++)
    {
        int min = INT_MAX;
        for(int j = 0; j <= i; j++)
        {
            if(dp[j] < min)
            {
                min = dp[j];
                *idx_min = j;
            }
        }
        if(dp[i] - min > max)
        {
            max = dp[i] - min;
            *idx_max = i;
        }
    }

    return max;
}

int main(int argc, char *argv[])
{
    int arr[] = {1,-2,3,10,-4,7,2,-5};
    int size = sizeof(arr)/sizeof(int);
    int idx_min = 0;
    int idx_max = 0;
    int r = MaxOfSum(arr, size, &idx_min, &idx_max);
    printf("max = %d, idx_min = %d, idx_max = %d\n", r, idx_min, idx_max);
    
    return 0;
}