#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SelectNode(int *dp, int start, int *idx1, int *idx2, int *pbool)
{
    //[0..start]
    int min1 = 1000;
    int min2 = 1000;
    *idx1 = -1;
    *idx2 = -1;

    for(int i = 0; i < start; i++)
    {
        if(pbool[i] == 0)
        {
            if(dp[i] <= min1)
            {
                min2 = min1;
                *idx2 = *idx1;
                min1 = dp[i];
                *idx1 = i;
            }
            else if(dp[i] <= min2)
            {
                *idx2 = i;
                min2 = dp[i];
            }
        }
        
    }
    pbool[*idx1] = 1;
    pbool[*idx2] = 1;
}

void GetResult(int *dp, int start, int dpsz, int *pbool)
{
    int min_idx1 = -1;
    int min_idx2 = -1;
    for(int i = start; i < dpsz; i++)
    {
        SelectNode(dp, i, &min_idx1, &min_idx2, pbool);
        printf("dp[%d] = %d, dp[%d] = %d\n", min_idx1, dp[min_idx1], min_idx2, dp[min_idx2]);
        dp[i] = dp[min_idx1] + dp[min_idx2];
    }
}

//找到数组中的最小值和第二最小值
void p(int *arr, int sz, int *idx1, int *idx2)
{
    idx1 = 0;
    idx2 = 0;
    int min1 = arr[*idx1];
    int min2 = arr[*idx2];

    for(int i = 0; i < sz; i++)
    {
        if(arr[i] <= min1)
        {
            min2 = min1;
            min1 = arr[i];
            *idx2 = *idx1;
            *idx1 = i;
        }
        else if(arr[i] <= min2)
        {
            *idx2 = i;
            min2 = arr[i];
        }
    }


}

int main(int argc, char *argv[])
{
    int arr[] = {5,3,4,2,1};
    int arr_len = sizeof(arr) / sizeof(int);
    int sz = 2 * arr_len - 1;

    int *dp = (int *)malloc(sz * sizeof(int));
    memset(dp, 0, sz * sizeof(int));
    int *pbool = (int *)malloc(sz * sizeof(int));
    memset(pbool, 0, sz * sizeof(int));

    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        dp[i] = arr[i];
    }

    GetResult(dp, arr_len, sz, pbool);

    for(int i = 0; i < sz; i++)
    {
        printf("%3d", dp[i]);
    }
    printf("\n");
    return 0;
}