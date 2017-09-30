#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cnt = 0;

void process(int idx, int *nums, int numsSize, int target, int *result, int **dp)
{
    //int ret = 0;
    if(idx >= numsSize)
    {
        //ret = target == 0 ? 1 : 0;
        if(target == 0)
        {
            //ret = 1;
            for(int i = 0; i < numsSize; i++)
            {
                printf("%4d", result[i]);
            }
            printf("\n");
        }
        else
        {
            //ret = 0;
        }
        return;
    }

    for(int i = 0; i * nums[idx] <= target; i++)
    {
        result[idx] = i * nums[idx];
        process(idx + 1, nums, numsSize, target - i * nums[idx], result, dp);
    }
    
}

int **coins(int *nums, int numsSize, int target)
{
    if(nums == NULL || numsSize <= 0 || target < 0)
    {
        return NULL;
    }
    cnt = 0;

    int *result = (int *)malloc(numsSize * sizeof(int));
    memset(result, 0, numsSize * sizeof(int));

    int **dp = (int **)malloc(1000 * sizeof(int *));
    
    process(0, nums, numsSize, target, result, dp);
    return dp;
}

int main(int argc, char *argv[])
{
    int nums[] = {5,10,25,1};
    int numsSize = sizeof(nums) / sizeof(int);
    int aim = 15;
    coins(nums, numsSize, aim);
    
}