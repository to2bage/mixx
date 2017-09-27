#include <stdio.h>
#include <stdlib.h>

int process(int idx, int *nums, int numsSize, int aim)
{
    int res = 0;
    if(idx >= numsSize)
    {
        res = aim == 0 ? 1 : 0;
    }
    else
    {
        for(int i = 0; i * nums[idx] <= aim; i++)
        {
            res += process(idx + 1, nums, numsSize, aim - i * nums[idx]);
        }
    }
    return res;
}

int coins(int *nums, int numsSize, int aim)
{
    if(nums == NULL || numsSize <= 0 || aim < 0)
    {
        return 0;
    }

    return process(0, nums, numsSize, aim);
}

int main(int argc, char *argv[])
{
    int nums[] = {5,10,25,1};
    int numsSize = sizeof(nums) / sizeof(int);
    int aim = 15;
    int res = coins(nums, numsSize, aim);
    printf("res = %d\n", res);

    return 0;
}