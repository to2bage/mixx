#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize) 
{
    if(nums == NULL || numsSize <= 0)
    {
        return 1;
    }

    nums--;
    int i = 1;
    while(i <= numsSize)
    {
        if(nums[i] == i)
        {
            ++i;
        }
        else if(nums[i] > i)
        {
            //交换nums[i] 和 nums[nums[i]]的值
            int tmp = nums[i];
            nums[i] = nums[nums[i]];
            nums[tmp] = tmp;
        }
        else if(nums[i] < i || nums[i] >= numsSize)
        {
            //抛弃
            nums[i] = nums[numsSize];
            --numsSize;
        }
    }
    return i;
}

int main(int arg, char *argv[])
{
    //int nums[] = {1,2,0};
    int nums[] = {3,4,-1,1};
    int numsSize = sizeof(nums) / sizeof(int);
    int missing_number = firstMissingPositive(nums, numsSize);
    printf("missing_number = %d\n", missing_number);

    return 0;
}