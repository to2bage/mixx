#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int process(int idx, int *nums, int numsSize, int target, int *result)
{
    int ret = 0;
    if(idx >= numsSize)
    {
        ret = target == 0 ? 1 : 0;
        return ret;
    }

    for(int i = 0; i * nums[idx] <= target; i++)
    {
        ret += process(idx + 1, nums, numsSize, target - i * nums[idx], result);
    }
    return ret;
}

int coins(int *nums, int numsSize, int target)
{
    if(nums == NULL || numsSize <= 0 || target < 0)
    {
        return -1;
    }
    int *result = (int *)malloc(1000 * sizeof(int));
    memset(result, 0, 1000 * sizeof(int));

    return process(0, nums, numsSize, target, result);
}

int main(int argc, char *argv[])
{
    int nums[] = {5,10,25,1};
    int numsSize = sizeof(nums) / sizeof(int);
    int aim = 15;
    int res = coins(nums, numsSize, aim);
    printf("res = %d\n", res);
}